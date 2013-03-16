//created by James Curnalia

package edu.ysu.jwcurnalia.finalproject;

import java.util.Random;

import edu.ysu.jwcurnalia.finalproject.Preferences;

import edu.ysu.jwcurnalia.finalproject.R;

import android.app.Activity;
import android.content.Context;
import android.content.SharedPreferences;
import android.os.Bundle;
import android.preference.PreferenceManager;
import android.view.View;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.TextView;

public class Battle extends Activity {

	private static final int SHOW_PREFERENCES = 1;

	private final Random myRandom = new Random();

	private String CHAR_OPTION = "CHAR_OPTION";
	private String CHAR_NAME = "CHAR_NAME";
	private String SPEC_OPTION = "SPEC_OPTION";
	private String MON_STATE = "MON_STATE";
	private String MON_OPTION = "MON_OPTION";
	private String MON_MOD = "MON_MOD";

	private String charName;

	private int combatModifier;
	private int attackState;
	private int heroState;
	private int monState;
	private int monOption;
	private int monModifier;

	private int specialCounter;
	private int monsterCounter = 1;

	private int heroSTRStat;
	private int heroDEXStat;
	private int heroINTStat;
	private int heroHPStat;


	private int heroSTRStatdef;
	private int heroDEXStatdef;
	private int heroINTStatdef;

	private int monSTRStat;
	private int monDEXStat;
	private int monINTStat;
	private int monHPStat;

	private int monSTRStatdef;
	private int monDEXStatdef;
	private int monINTStatdef;

	private int heroDefense = heroDEXStat + myRandom.nextInt(20);

	private int heroAttack = heroSTRStat + myRandom.nextInt(20);
	private int heroBonus = (1 + heroSTRStat / 3);

	private int heroDEXAttack = heroDEXStat + myRandom.nextInt(20);
	private int heroDEXBonus = (1 + heroDEXStat / 3);

	private int heroINTAttack = heroINTStat + myRandom.nextInt(20);
	private int heroINTBonus = (1 + heroINTStat / 3);

	private int monAttack = monSTRStat + myRandom.nextInt(20);
	private int monDEXAttack = monDEXStat + myRandom.nextInt(20);
	private int monINTAttack = monINTStat + myRandom.nextInt(20);

	private int monDefense = monDEXStat + myRandom.nextInt(20);
	private int monSTRDefense = monSTRStat + myRandom.nextInt(20);
	private int monINTDefense = monINTStat + myRandom.nextInt(20);

	private int monBonus = (1 + monSTRStat / 3);
	private int monDEXBonus = (1 + monDEXStat / 3);
	private int monINTBonus = (1 + monINTStat / 3);

	private Boolean ironMan;

	private Button btnattack;
	private Button btnspecial;

	private TextView heroname;
	private TextView heroclass;
	private TextView herostr;
	private TextView herodex;
	private TextView heroint;
	private TextView herocurrenthp;
	private TextView heromaxhp;

	private TextView monname;
	private TextView monclass;
	private TextView monstr;
	private TextView mondex;
	private TextView monint;
	private TextView moncurrenthp;
	private TextView monmaxhp;

	private ImageView heroportrait;
	private ImageView monportrait;

	@Override
	public void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.main_battle);

		Bundle b = getIntent().getExtras();
		heroState = b.getInt(CHAR_OPTION);
		charName = b.getString(CHAR_NAME);
		attackState = b.getInt(SPEC_OPTION);
		monState = b.getInt(MON_STATE);
		monOption = b.getInt(MON_OPTION);
		monModifier = b.getInt(MON_MOD);

		updateFromPreferences();
		initStats();
		populateStats(); 
	}

	private void updateFromPreferences() {
		Context context = getApplicationContext();
		SharedPreferences prefs = PreferenceManager
				.getDefaultSharedPreferences(context);

		int challengeIndex = prefs.getInt(Preferences.CHALLENGE_PER, 1);
		if (challengeIndex < 0)
			challengeIndex = 0;

		ironMan = prefs.getBoolean(Preferences.IRON_MAN_PER, false);

		combatModifier = challengeIndex - 1;

	}

	public void initStats() {

		heroname = (TextView)findViewById(R.id.heroname);
		heroclass = (TextView)findViewById(R.id.heroclass);
		herostr = (TextView)findViewById(R.id.strvalue);
		herodex = (TextView)findViewById(R.id.dexvalue);
		heroint = (TextView)findViewById(R.id.intvalue);
		herocurrenthp = (TextView)findViewById(R.id.hpvalue);
		heromaxhp = (TextView)findViewById(R.id.maxhp);

		heroportrait = (ImageView)findViewById(R.id.portraithero);

		monname = (TextView)findViewById(R.id.monsname);
		monclass = (TextView)findViewById(R.id.classmon);
		monstr = (TextView)findViewById(R.id.strvaluemon);
		mondex = (TextView)findViewById(R.id.dexvaluemon);
		monint = (TextView)findViewById(R.id.intvaluemon);
		moncurrenthp = (TextView)findViewById(R.id.monhpvalue);
		monmaxhp = (TextView)findViewById(R.id.monmaxhp);

		monportrait = (ImageView)findViewById(R.id.portraitmon);

		btnattack = (Button)findViewById(R.id.btnattack);
		btnspecial = (Button)findViewById(R.id.btnspecial);

		btnattack.setOnClickListener(new View.OnClickListener() {

			public void onClick(View view) {

				attack();

			}
		});

		btnspecial.setOnClickListener(new View.OnClickListener() {

			public void onClick(View view) {

				special();

			}
		});

	}

	public void attack() {

		battleStats();

		heroAttack();

		if (monsterCounter > 0) {

			monAttack();

			if (monsterCounter <= 0) {

				monsterCounter = 2;

				monSpecial();

			}
		}

		if (heroHPStat > 0 && monHPStat > 0) {

			herocurrenthp.setText(Integer.toString(heroHPStat));
			moncurrenthp.setText(Integer.toString(monHPStat));

			if (specialCounter > 0)
				specialCounter--;
			if (specialCounter <= 0) {

				herostr.setText(Integer.toString(heroSTRStatdef));
				herodex.setText(Integer.toString(heroDEXStatdef));
				heroint.setText(Integer.toString(heroINTStatdef));

				monstr.setText(Integer.toString(monSTRStatdef));
				mondex.setText(Integer.toString(heroDEXStatdef));
				monint.setText(Integer.toString(heroINTStatdef));

				btnspecial.setVisibility(View.VISIBLE);

			}
			return;
		}

		if (heroHPStat <= 0 || monHPStat <= 0) {

			if (heroHPStat <= 0) {
				// hero dead
				Battle.this.setResult(RESULT_CANCELED);
				finish();

			}

			if (monHPStat <= 0) {
				Battle.this.setResult(RESULT_OK);
				finish();
			}
		}
	}

	public void special() {

		battleStats();

		heroSpecial();

		if (monsterCounter > 0) {

			monAttack();

			if (monsterCounter <= 0) {

				monsterCounter = 2;

				monSpecial();

			}
		}

		if (heroHPStat > 0 && monHPStat > 0) {

			herocurrenthp.setText(Integer.toString(heroHPStat));
			moncurrenthp.setText(Integer.toString(monHPStat));

			if (specialCounter > 0)
				specialCounter--;
			if (specialCounter <= 0) {

				herostr.setText(Integer.toString(heroSTRStatdef));
				herodex.setText(Integer.toString(heroDEXStatdef));
				heroint.setText(Integer.toString(heroINTStatdef));

				monstr.setText(Integer.toString(monSTRStatdef));
				mondex.setText(Integer.toString(heroDEXStatdef));
				monint.setText(Integer.toString(heroINTStatdef));

				btnspecial.setVisibility(View.VISIBLE);
			}

			return;
		}

		if (heroHPStat <= 0 || monHPStat <= 0) {

			if (heroHPStat <= 0) {
				// hero dead

				if (ironMan) {
					// delete character
				}
			}

			if (monHPStat <= 0) {
				// monster dead
			}
		}
	}

	public void populateStats() {

		heroname.setText(charName);
		// will link to DB in future

		switch (heroState) {

		case (0):

			heroclass.setText(R.string.fighter);
			herostr.setText("7");
			herodex.setText("5");
			heroint.setText("3");
			herocurrenthp.setText("10");
			heromaxhp.setText("10");

			heroportrait.setBackgroundResource(R.drawable.paizo_fighter);

			break;

		case (1):

			heroclass.setText(R.string.thief);
			herostr.setText("5");
			herodex.setText("7");
			heroint.setText("3");
			herocurrenthp.setText("8");
			heromaxhp.setText("8");

			heroportrait.setBackgroundResource(R.drawable.paizo_thief);

			break;

		case (2):

			heroclass.setText(R.string.mage);
			herostr.setText("3");
			herodex.setText("5");
			heroint.setText("7");
			herocurrenthp.setText("6");
			heromaxhp.setText("6");

			heroportrait.setBackgroundResource(R.drawable.paizo_mage);

			break;

		}

		heroSTRStatdef = Integer.parseInt(herostr.getText().toString());
		heroDEXStatdef = Integer.parseInt(herodex.getText().toString());
		heroINTStatdef = Integer.parseInt(heroint.getText().toString());

		monSTRStatdef = Integer.parseInt(herostr.getText().toString());
		monDEXStatdef = Integer.parseInt(mondex.getText().toString());
		monINTStatdef = Integer.parseInt(monint.getText().toString());

		
	}

	public void battleStats() {

		heroSTRStat = Integer.parseInt(herostr.getText().toString());
		heroDEXStat = Integer.parseInt(herodex.getText().toString());
		heroINTStat = Integer.parseInt(heroint.getText().toString());
		heroHPStat = Integer.parseInt(herocurrenthp.getText().toString());

		monSTRStat = Integer.parseInt(herostr.getText().toString());
		monDEXStat = Integer.parseInt(mondex.getText().toString());
		monINTStat = Integer.parseInt(monint.getText().toString());
		monHPStat = Integer.parseInt(moncurrenthp.getText().toString());

		heroDefense = heroDEXStat + myRandom.nextInt(20);

		heroAttack = heroSTRStat + myRandom.nextInt(20);
		heroBonus = (1 + heroSTRStat / 3);

		heroDEXAttack = heroDEXStat + myRandom.nextInt(20);
		heroDEXBonus = (1 + heroDEXStat / 3);

		heroINTAttack = heroINTStat + myRandom.nextInt(20);
		heroINTBonus = (1 + heroINTStat / 3);

		monAttack = monSTRStat + myRandom.nextInt(20);
		monDEXAttack = monDEXStat + myRandom.nextInt(20);
		monINTAttack = monINTStat + myRandom.nextInt(20);

		monDefense = monDEXStat + myRandom.nextInt(20);
		monSTRDefense = monSTRStat + myRandom.nextInt(20);
		monINTDefense = monINTStat + myRandom.nextInt(20);

		monBonus = (1 + monSTRStat / 3);
		monDEXBonus = (1 + monDEXStat / 3);
		monINTBonus = (1 + monINTStat / 3);

	}

	public void heroAttack() {
		switch (heroState) {
		case (0):

			if (heroAttack > monDefense) {
				monHPStat = monHPStat - heroBonus;
			}

			break;

		case (1):

			if (heroDEXAttack > monDefense) {
				monHPStat = monHPStat - heroBonus;
			}

			break;

		case (2):

			if (heroINTAttack > monDefense) {
				monHPStat = monHPStat - heroBonus;
			}

			break;
		}
	}

	public void monAttack() {
		if (monState == 0) {
			if (monAttack > heroDefense) {
				heroHPStat = heroHPStat - monBonus;
			}
		}
		if (monState > 0) {
			if (monsterCounter > 0) {
				switch (monState) {
				case (1):
					if (monAttack > heroDefense) {
						heroHPStat = heroHPStat - monBonus + 2;
					}
					break;

				case (2):
					if (monDEXAttack > heroDefense) {
						heroHPStat = heroHPStat - monDEXBonus;
					}
					break;

				case (3):
					if (monINTAttack > heroDefense) {
						heroHPStat = heroHPStat - monINTBonus;
					}
					break;
				}
			}
		}
	}

	public void heroSpecial() {

		specialCounter = 3;
		btnspecial.setVisibility(View.GONE);

		switch (heroState) {
		case (0):

			switch (attackState) {
			case (0):

				if (heroAttack - 2 > monDefense) {
					monHPStat = monHPStat - (heroBonus + 2);
				}

				break;

			case (1):

				if (heroAttack > monSTRDefense) {
					monHPStat = monHPStat - 1;
					monSTRStat = monSTRStat - 2;
					monstr.setText(Integer.toString(monSTRStat));

				}

				break;

			case (2):

				if (heroAttack > monDefense) {
					monHPStat = monHPStat - 1;
					monDEXStat = monDEXStat - 2;
					mondex.setText(Integer.toString(monDEXStat));

				}

				break;
			}

		case (1):

			switch (attackState) {
			case (0):

				if (heroDEXAttack > monDefense) {
					heroDEXStat = heroDEXStat + 2;
					herodex.setText(Integer.toString(heroDEXStat));
					break;
				}

				break;

			case (1):

				if (heroDEXAttack - 2 > monDefense) {
					monHPStat = monHPStat - (heroDEXBonus + 2);
				}

				break;

			case (2):

				if (heroDEXAttack - 2 > monDefense) {
					monHPStat = monHPStat - (heroDEXBonus + 2);
					heroDEXStat = heroDEXStat + 2;
					herodex.setText(Integer.toString(heroDEXStat));
					break;
				}

				break;
			}

		case (2):

			switch (attackState) {
			case (0):

				monHPStat = monHPStat - 2;

				break;

			case (1):

				if (heroINTAttack > monINTDefense) {
					monSTRStat = monSTRStat - 2;
					monstr.setText(Integer.toString(monSTRStat));
					monDEXStat = monDEXStat - 2;
					mondex.setText(Integer.toString(monDEXStat));
				}

				break;

			case (2):

				if (heroINTAttack > monINTDefense) {
					monHPStat = monHPStat - (heroINTBonus + 2);
				}

				break;
			}
		}

	}

	public void monSpecial() {

		if (monState == 0) {
			if (monAttack > heroDefense) {
				heroHPStat = heroHPStat - monBonus;
			}
		}
		if (monState > 0) {

			switch (monState) {
			case (1):
				if (monAttack - 2 > heroDefense) {
					heroHPStat = heroHPStat - (monBonus + 2);
				}
				break;

			case (2):
				if (monDEXAttack - 2 > heroDefense) {
					heroHPStat = heroHPStat - (monDEXBonus + 2);
					heroDEXStat = heroDEXStat - 2;
					herodex.setText(Integer.toString(heroDEXStat));
				}
				break;

			case (3):
				if (monINTAttack > heroDefense) {
					heroHPStat = heroHPStat - (monINTBonus);
					heroSTRStat = heroSTRStat - 2;
					herostr.setText(Integer.toString(heroSTRStat));
				}
				break;
			}
		}

	}

}