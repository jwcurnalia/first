//created by James Curnalia


package edu.ysu.jwcurnalia.finalproject;

import edu.ysu.jwcurnalia.finalproject.Preferences;
import edu.ysu.jwcurnalia.finalproject.CastleQuestActivity;

import edu.ysu.jwcurnalia.finalproject.R;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ImageView;
import android.widget.Spinner;
import android.widget.TextView;
import android.widget.AdapterView.OnItemSelectedListener;

public class CharacterCreation extends Activity {
	
	
	private static final int SHOW_PREFERENCES = 1;
	static final private int PREFERENCE_ITEM = Menu.FIRST;
	
	Spinner charSpinner;
	
	private int buttonStatus;
	private int charIndex = 0;
	
	private String CHAR_OPTION = "CHAR_OPTION";
	private String CHAR_NAME = "CHAR_NAME";
	
	private String charName;
	
	private TextView heroclass;
    private TextView herostr;
    private TextView herodex;
    private TextView heroint;
    private TextView herohp;
    
    private EditText heroname;
    
    private ImageView heroportrait;

	
	
	@Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.character_creation);
        
        charSpinner = (Spinner)findViewById(R.id.spinner_charclass);
        initStats();
        populateSpinners();
        
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
      super.onOptionsItemSelected (item);
      
      int selected = item.getItemId();
      
    	if (PREFERENCE_ITEM == selected) {
    	  Intent i = new Intent(this, Preferences.class);
          startActivityForResult(i, SHOW_PREFERENCES);
      	  return true;
      	}
    	else
    		return false;
    }

    
  
    public void myResetHandler() {
	    
	  switch(buttonStatus) {
	  
	  case(1):
		  
		  	charName = heroname.getText().toString();
		  
		    saveCharacter();
	  		
	  		Intent i = new Intent(this, CastleQuestActivity.class);
	  		Bundle b = new Bundle();
	  		b.putInt(CHAR_OPTION, charIndex); 
	  		b.putString(CHAR_NAME, charName);
	  		i.putExtras(b);
	  		setResult(RESULT_OK, i);
	  		finish();
	  		
	  		return;
		   
	  case(2):
		  	CharacterCreation.this.setResult(RESULT_CANCELED);
		  	finish();
		
		  	return;
     }
	  
    }
    
    public void saveCharacter() {
    	//insert Character into DB
    }
    
    public void populateSpinners() {	  
    	 
    	int spinner_dd_item = android.R.layout.simple_spinner_dropdown_item;  
    	  
        ArrayAdapter<CharSequence> fAdapter;
        fAdapter = ArrayAdapter.createFromResource(this, R.array.character_options,
                                                   android.R.layout.simple_spinner_item);
        fAdapter.setDropDownViewResource(spinner_dd_item); 
        charSpinner.setAdapter(fAdapter);
        
       charSpinner.setOnItemSelectedListener(new OnItemSelectedListener() 
        {
            @Override
            public void onItemSelected(AdapterView<?> parentView, View selectedItemView, int position, long id) 
            {
            	charIndex = position;
            	updateUI();
            }

            @Override
            public void onNothingSelected(AdapterView<?> parentView) 
            {
            	//do nothing
            }
        });
       
      }
    
    public void initStats() {
    	
  		heroclass = (TextView)findViewById(R.id.sampheroclass);
  		herostr = (TextView)findViewById(R.id.sampstrvalue);
        herodex = (TextView)findViewById(R.id.sampdexvalue);
        heroint = (TextView)findViewById(R.id.sampintvalue);
        herohp = (TextView)findViewById(R.id.samphpvalue);
        
        heroname = (EditText)findViewById(R.id.sampname);
        
        heroportrait = (ImageView)findViewById(R.id.portraitsample);
    }
    
    public void updateUI() {
    	
    	switch(charIndex) {
    	
    	case(0):
    		
    		heroclass.setText(R.string.fighter);
    		herostr.setText("7");
    		herodex.setText("5");
    		heroint.setText("3");
    		herohp.setText("10");
    		
    		heroportrait.setBackgroundResource(R.drawable.paizo_fighter);
    		
    		break;
    		
    	case(1):
    		
    		heroclass.setText(R.string.thief);
    		herostr.setText("5");
    		herodex.setText("7");
    		heroint.setText("3");
    		herohp.setText("8");
    		
    		heroportrait.setBackgroundResource(R.drawable.paizo_thief);
    		
    		break;
    		
    	case(2):
    		
    		heroclass.setText(R.string.mage);
    		herostr.setText("3");
    		herodex.setText("5");
    		heroint.setText("7");
    		herohp.setText("6");
    		
    		heroportrait.setBackgroundResource(R.drawable.paizo_mage);
    		
    		break;
    		
    	}
    	
    }
    
}


