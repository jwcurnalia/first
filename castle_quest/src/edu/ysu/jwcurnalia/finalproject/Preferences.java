//James Curnalia

package edu.ysu.jwcurnalia.finalproject;

import edu.ysu.jwcurnalia.finalproject.R;

import android.app.Activity;
import android.content.Context;
import android.content.SharedPreferences;
import android.content.SharedPreferences.Editor;
import android.os.Bundle;
import android.preference.PreferenceManager;
import android.view.View;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.CheckBox;
import android.widget.Spinner;

public class Preferences extends Activity {

	public static final String CHALLENGE_PER = "CHALLENGE_PER";
	public static final String IRON_MAN_PER = "IRON_MAN_PER";

	SharedPreferences prefs;

	Spinner challengeSpinner;

	CheckBox ironBox;

	private int challengeIndex;
	private int buttonStatus;

	@Override
	public void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.preferences);

		challengeSpinner = (Spinner) findViewById(R.id.spinner_challenge);

		populateSpinners();

		Context context = getApplicationContext();
		prefs = PreferenceManager.getDefaultSharedPreferences(context);
		

		ironBox =(CheckBox)findViewById(R.id.iron_man);

		updateUIFromPreferences();
		
		Button okButton = (Button) findViewById(R.id.okButton);
		okButton.setOnClickListener(new View.OnClickListener() {

			public void onClick(View view) {

				buttonStatus = 1;
				myResetHandler();

			}
		});

		Button cancelButton = (Button) findViewById(R.id.cancelButton);
		cancelButton.setOnClickListener(new View.OnClickListener() {

			public void onClick(View view) {

				buttonStatus = 2;
				myResetHandler();

			}
		});

		Button resetMenuButton = (Button) findViewById(R.id.resetMenuButton);
		resetMenuButton.setOnClickListener(new Button.OnClickListener() {

			public void onClick(View v) {

				buttonStatus = 3;
				myResetHandler();
			}
		});
	}

	public void myResetHandler() {

		switch (buttonStatus) {

		case (1):

			savePreferences();
			Preferences.this.setResult(RESULT_OK);
			finish();

			return;

		case (2):
			Preferences.this.setResult(RESULT_CANCELED);
			finish();

			return;
		case (3):

			Context context = getApplicationContext();
			SharedPreferences prefs = PreferenceManager
					.getDefaultSharedPreferences(context);
			SharedPreferences.Editor editor = prefs.edit();

			editor.putInt(Preferences.CHALLENGE_PER,
					Integer.parseInt(getString(R.string.challengeindex)));
			editor.putBoolean(IRON_MAN_PER, false);

			editor.commit();

			Preferences.this.setResult(RESULT_OK);
			finish();

			return;
		}
	}

	private void populateSpinners() {

		int spinner_dd_item = android.R.layout.simple_spinner_dropdown_item;

		ArrayAdapter<CharSequence> fAdapter;
		fAdapter = ArrayAdapter
				.createFromResource(this, R.array.challenge_options,
						android.R.layout.simple_spinner_item);
		fAdapter.setDropDownViewResource(spinner_dd_item);
		challengeSpinner.setAdapter(fAdapter);

	}

	private void updateUIFromPreferences() {

		int challengeIndex = prefs.getInt(CHALLENGE_PER,
				Integer.parseInt(getString(R.string.challengeindex)));
		Boolean ironCheck = prefs.getBoolean(IRON_MAN_PER, false);

		challengeSpinner.setSelection(challengeIndex);
		ironBox.setChecked(ironCheck);

	}

	private void savePreferences() {
		challengeIndex = challengeSpinner.getSelectedItemPosition();
		Boolean ironSet = ironBox.isChecked();

		Editor editor = prefs.edit();
		editor.putInt(CHALLENGE_PER, challengeIndex);
		editor.putBoolean(IRON_MAN_PER, ironSet);

		editor.commit();
	}
}