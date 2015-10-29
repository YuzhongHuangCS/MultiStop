package org.pillowsky.multistop;

import android.app.Activity;
import android.content.Context;
import android.os.Bundle;
import android.os.CountDownTimer;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ArrayAdapter;
import android.widget.BaseAdapter;
import android.widget.Button;
import android.widget.Chronometer;
import android.widget.ListView;
import android.widget.TextView;
import android.widget.Toast;

import java.util.ArrayList;

public class MainActivity extends Activity  {
    private MilliChronometer chronometer;
    private Button leftButton;
    private Button rightButton;
    private ListView multiStopView;
    private MultiStopAdapter multiStopAdapter;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        chronometer = (MilliChronometer)findViewById(R.id.chronometer);
        leftButton = (Button)findViewById(R.id.leftButton);
        rightButton = (Button)findViewById(R.id.rightButton);
        multiStopAdapter = new MultiStopAdapter(this);
        multiStopView = (ListView)findViewById(R.id.multiStopView);
        multiStopView.setAdapter(multiStopAdapter);
    }

    public void onLeftButtonClick(View view) {
        if (chronometer.isStarted()) {
            chronometer.stop();
            leftButton.setText("Start");
        } else {
            chronometer.start();
            leftButton.setText("Stop");
        }
    }

    public void onRightButtonClick(View view) {
        if (chronometer.isStarted()) {
            multiStopAdapter.addItem(chronometer.getTimeElapsed());
        } else {
            //reset()
            chronometer.reset();
        }
    }
}
