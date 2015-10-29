package org.pillowsky.multistop;

import android.app.Activity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.ListView;

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
        multiStopView = (ListView)findViewById(R.id.multiStopView);
        multiStopAdapter = new MultiStopAdapter(this);
        multiStopView.setAdapter(multiStopAdapter);
    }

    public void onLeftButtonClick(View view) {
        if (chronometer.isStarted()) {
            chronometer.stop();
            leftButton.setText("Start");
            rightButton.setText("Reset");
        } else {
            chronometer.start();
            leftButton.setText("Stop");
            rightButton.setText("Count");
        }
    }

    public void onRightButtonClick(View view) {
        if (chronometer.isStarted()) {
            multiStopAdapter.addStop(chronometer.getElapsed());
        } else {
            multiStopAdapter.reset();
            chronometer.reset();
        }
    }
}
