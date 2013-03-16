//created by James Curnalia

package edu.ysu.jwcurnalia.finalproject;

import java.util.Random;

import edu.ysu.jwcurnalia.finalproject.Preferences;
import edu.ysu.jwcurnalia.finalproject.Battle;
import edu.ysu.jwcurnalia.finalproject.R;

import android.app.Activity;
import android.content.Context;
import android.content.Intent;
import android.content.SharedPreferences;
import android.location.Criteria;
import android.location.Location;
import android.location.LocationManager;
import android.os.Bundle;
import android.preference.PreferenceManager;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.Spinner;
import android.widget.TextView;
import android.widget.Toast;
import android.widget.AdapterView.OnItemSelectedListener;

public class HeroHome extends Activity {

	private static final int SHOW_PREFERENCES = 1;
	private static final int BATTLE = 2;
	static final private int PREFERENCE_ITEM = Menu.FIRST;
	private final Random myRandom = new Random();

	private String CHAR_OPTION = "CHAR_OPTION";
	private String CHAR_NAME = "CHAR_NAME";
	private String SPEC_OPTION = "SPEC_OPTION";
	private String MON_STATE = "MON_STATE";
	private String MON_OPTION = "MON_OPTION";
	private String MON_MOD = "MON_MOD";

	private Boolean ironMan;

	private String charName;
	private int specIndex;
	private int heroState;
	private int monState = 0;
	private int monOption = 0;
	private int monModifier = 0;

	private int battleCounter = 0;

	Spinner specSpinner;
	
	MenuItem preferenceItem;

	private TextView heroname;
	private TextView heroclass;
	private TextView herostr;
	private TextView herodex;
	private TextView heroint;
	private TextView herohp;
	private TextView heromaxhp;
	private TextView heroxp;

	private ImageView heroportrait;

	private Button battleButton;

	@Override
	public void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.hero_main);

		Bundle b = getIntent().getExtras();
		heroState = b.getInt(CHAR_OPTION);
		charName = b.getString(CHAR_NAME);

		specSpinner = (Spinner) findViewById(R.id.spinner_main);
		populateSpinners();
		initStats();
		populateStats();
		updateFromPreferences();

		Button exploreButton = (Button) findViewById(R.id.btnexplore);
		exploreButton.setOnClickListener(new View.OnClickListener() {

			public void onClick(View view) {

				explore();

			}
		});

		battleButton = (Button) findViewById(R.id.btnbattle);
		battleButton.setOnClickListener(new View.OnClickListener() {

			public void onClick(View view) {

				launchBattle();

			}
		});

		battleButton.setVisibility(View.GONE);
	}

	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		super.onCreateOptionsMenu(menu);

		preferenceItem = menu.add(0, PREFERENCE_ITEM, Menu.NONE,
				R.string.preferencebutton);

		return true;
	}

	@Override
	public boolean onOptionsItemSelected(MenuItem item) {
		super.onOptionsItemSelected(item);

		int selected = item.getItemId();

		if (PREFERENCE_ITEM == selected) {
			Intent i = new Intent(this, Preferences.class);
			startActivityForResult(i, SHOW_PREFERENCES);
			return true;
		} else
			return false;
	}

	public void explore() {
		
		 LocationManager locationManager;
		    String context = Context.LOCATION_SERVICE;
		    locationManager = (LocationManager)getSystemService(context);

		    Criteria criteria = new Criteria();
		    criteria.setAccuracy(Criteria.ACCURACY_FINE);
		    criteria.setAltitudeRequired(false);
		    criteria.setBearingRequired(false);
		    criteria.setCostAllowed(true);
		    criteria.setPowerRequirement(Criteria.POWER_LOW);
		    String provider = locationManager.getBestProvider(criteria, true);
		    
		    if(provider == null)
		    	updateWithNewLocation(null);
		    
		    else {
			  Location location = locationManager.getLastKnownLocation(provider);
		    updateWithNewLocation(location);
		    }
		    
		    battleButton.setVisibility(View.VISIBLE);

	}

	private void updateWithNewLocation(Location location) {
		    
		    if (location != null) {
		      monOption = (int)location.getLatitude() % 3;
		      monModifier = (int)location.getLongitude() % 3;
		      
		    } 
		    else {
		    	monOption = myRandom.nextInt(3);
				monModifier = myRandom.nextInt(3);
		    }
		   
		  }
	
	public void launchBattle() {
		Intent i = new Intent(this, Battle.class);
		Bundle b = new Bundle();
		b.putInt(CHAR_OPTION, heroState);
		b.putString(CHAR_NAME, charName);
		b.putInt(SPEC_OPTION, specIndex);
		b.putInt(MON_STATE, monState);
		b.putInt(MON_OPTION, monOption);
		b.putInt(MON_MOD, monModifier);
		i.putExtras(b);
		startActivityForResult(i, BATTLE);
	}

	@Override
	public void onActivityResult(int requestCode, int resultCode, Intent data) {
		super.onActivityResult(requestCode, resultCode, data);

		if (requestCode == BATTLE) {
			if (resultCode == Activity.RESULT_OK) {
				if (battleCounter <= 3)
					battleCounter++;
				if (battleCounter == 3) {
					battleCounter++;
					monState = 1;
				}
				if (battleCounter == 4) {
					battleCounter = 0;
					monState = 0;
					Toast.makeText(this, "Encounter Cleared.",
							Toast.LENGTH_LONG).show();
				}

				int xp = Integer.parseInt(heroxp.getText().toString());
				xp++;
				heroxp.setText(Integer.toString(xp));
			} else if (resultCode == Activity.RESULT_CANCELED) {
				if (ironMan) {
					battleCounter = 0;
					monState = 0;
					Toast.makeText(this, "Encounter Failed.", Toast.LENGTH_LONG)
							.show();
				} else
					Toast.makeText(this, "You lost the battle.",
							Toast.LENGTH_LONG).show();
			}
		}
	}

	public void populateSpinners() {

		switch (heroState) {

		case (0):
			int spinner_dd_item = android.R.layout.simple_spinner_dropdown_item;

			ArrayAdapter<CharSequence> fAdapter;
			fAdapter = ArrayAdapter.createFromResource(this,
					R.array.fighter_options,
					android.R.layout.simple_spinner_item);
			fAdapter.setDropDownViewResource(spinner_dd_item);
			specSpinner.setAdapter(fAdapter);

			break;

		case (1):
			int spinner_ee_item = android.R.layout.simple_spinner_dropdown_item;

			ArrayAdapter<CharSequence> gAdapter;
			gAdapter = ArrayAdapter
					.createFromResource(this, R.array.thief_options,
							android.R.layout.simple_spinner_item);
			gAdapter.setDropDownViewResource(spinner_ee_item);
			specSpinner.setAdapter(gAdapter);

			break;

		case (2):
			int spinner_ff_item = android.R.layout.simple_spinner_dropdown_item;

			ArrayAdapter<CharSequence> hAdapter;
			hAdapter = ArrayAdapter.createFromResource(this,
					R.array.mage_options, android.R.layout.simple_spinner_item);
			hAdapter.setDropDownViewResource(spinner_ff_item);
			specSpinner.setAdapter(hAdapter);

			break;

		}
		specSpinner.setOnItemSelectedListener(new OnItemSelectedListener() {
			@Override
			public void onItemSelected(AdapterView<?> parentView,
					View selectedItemView, int position, long id) {
				specIndex = position;

			}

			@Override
			public void onNothingSelected(AdapterView<?> parentView) {
				// do nothing
			}
		});
	}

	public void initStats() {

		heroname = (TextView) findViewById(R.id.mainheroname);
		heroclass = (TextView) findViewById(R.id.mainheroclass);
		herostr = (TextView) findViewById(R.id.mainstrvalue);
		herodex = (TextView) findViewById(R.id.maindexvalue);
		heroint = (TextView) findViewById(R.id.mainintvalue);
		herohp = (TextView) findViewById(R.id.mainhpvalue);
		heromaxhp = (TextView) findViewById(R.id.mainmaxhp);
		heroxp = (TextView) findViewById(R.id.heroxp);

		heroportrait = (ImageView) findViewById(R.id.fullportrait);
	}

	public void populateStats() {

		heroname.setText(charName);
		// will link to DB in future

		switch (heroState) {

		case (0):

			heroclass.setText("Fighter");
			herostr.setText("7");
			herodex.setText("5");
			heroint.setText("3");
			herohp.setText("10");
			heromaxhp.setText("10");
			heroxp.setText("0");

			heroportrait.setBackgroundResource(R.drawable.paizo_fighter);

			break;

		case (1):

			heroclass.setText("Thief");
			herostr.setText("5");
			herodex.setText("7");
			heroint.setText("3");
			herohp.setText("8");
			heromaxhp.setText("8");
			heroxp.setText("0");

			heroportrait.setBackgroundResource(R.drawable.paizo_thief);

			break;

		case (2):

			heroclass.setText("Mage");
			herostr.setText("3");
			herodex.setText("5");
			heroint.setText("7");
			herohp.setText("6");
			heromaxhp.setText("6");
			heroxp.setText("0");

			heroportrait.setBackgroundResource(R.drawable.paizo_mage);

			break;

		}

	}

	private void updateFromPreferences() {
		Context context = getApplicationContext();
		SharedPreferences prefs = PreferenceManager
				.getDefaultSharedPreferences(context);

		ironMan = prefs.getBoolean(Preferences.IRON_MAN_PER, false);

	}
}
