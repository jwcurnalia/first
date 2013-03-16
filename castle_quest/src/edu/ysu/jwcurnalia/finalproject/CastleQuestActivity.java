//created by James Curnalia

package edu.ysu.jwcurnalia.finalproject;

import edu.ysu.jwcurnalia.finalproject.Preferences;
import edu.ysu.jwcurnalia.finalproject.CharacterCreation;
import edu.ysu.jwcurnalia.finalproject.HeroHome;

import edu.ysu.jwcurnalia.finalproject.R;

import android.app.Activity;
import android.content.Context;
import android.content.Intent;
import android.content.SharedPreferences;
import android.os.Bundle;
import android.preference.PreferenceManager;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.Button;
import android.widget.Spinner;
import android.widget.Toast;

public class CastleQuestActivity extends Activity {

	private static final int SHOW_PREFERENCES = 1;
	private static final int CHAR_CREATION = 2;
	static final private int PREFERENCE_ITEM = Menu.FIRST;

	private int combatModifier;

	Boolean ironMan;

	private int charIndex;

	private Button resumeButton;

	private String CHAR_OPTION = "CHAR_OPTION";
	private String CHAR_NAME = "CHAR_NAME";

	private String charName;

	@Override
	public void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.main);

		updateFromPreferences();

		Button createButton = (Button) findViewById(R.id.btncreatechar);
		createButton.setOnClickListener(new View.OnClickListener() {

			public void onClick(View view) {

				characterCreation();

			}
		});

		resumeButton = (Button) findViewById(R.id.btnresumechar);
		resumeButton.setOnClickListener(new View.OnClickListener() {

			public void onClick(View view) {

				characterDBM();

			}
		});

		resumeButton.setVisibility(View.GONE);

	}

	private void updateFromPreferences() {
		Context context = getApplicationContext();
		SharedPreferences prefs = PreferenceManager
				.getDefaultSharedPreferences(context);

		int challengeIndex = prefs.getInt(Preferences.CHALLENGE_PER,
				Integer.parseInt(getString(R.string.challengeindex)));
		if (challengeIndex < 0)
			challengeIndex = 0;

		ironMan = prefs.getBoolean(Preferences.IRON_MAN_PER, false);

		combatModifier = challengeIndex - 1;

	}

	@Override
	public void onActivityResult(int requestCode, int resultCode, Intent data) {
		super.onActivityResult(requestCode, resultCode, data);

		if (requestCode == SHOW_PREFERENCES) {
			if (resultCode == Activity.RESULT_OK) {
				updateFromPreferences();
			} else if (resultCode == Activity.RESULT_CANCELED)
				Toast.makeText(this, "No change made to preferences.",
						Toast.LENGTH_LONG).show();
		}

		if (requestCode == CHAR_CREATION) {
			if (resultCode == Activity.RESULT_OK) {

				Bundle extras = data.getExtras();
				charIndex = extras.getInt(CHAR_OPTION);
				charName = extras.getString(CHAR_NAME);

				resumeButton.setVisibility(View.VISIBLE);

			} else if (resultCode == Activity.RESULT_CANCELED)
				Toast.makeText(this, "No character created.", Toast.LENGTH_LONG)
						.show();
		}
	}

	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		super.onCreateOptionsMenu(menu);

		MenuItem preferenceItem = menu.add(0, PREFERENCE_ITEM, Menu.NONE,
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

	public void characterCreation() {
		Intent i = new Intent(this, CharacterCreation.class);
		startActivityForResult(i, CHAR_CREATION);
	}

	public void characterDBM() {
		Intent i = new Intent(this, HeroHome.class);
		Bundle b = new Bundle();
		b.putInt(CHAR_OPTION, charIndex);
		b.putString(CHAR_NAME, charName);
		i.putExtras(b);
		startActivity(i);
	}

}