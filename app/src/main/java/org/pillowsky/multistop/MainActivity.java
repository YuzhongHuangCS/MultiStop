package org.pillowsky.multistop;

import android.app.Activity;
import android.content.Context;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.widget.Button;
import android.widget.ListView;

public class MainActivity extends Activity  {
    private LayoutInflater inflater;
    private MilliChronometer chronometer;
    private Button leftButton;
    private Button rightButton;
    private ListView multiStopView;
    private MultiStopAdapter multiStopAdapter;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        inflater = (LayoutInflater)getSystemService(Context.LAYOUT_INFLATER_SERVICE);
        chronometer = (MilliChronometer)findViewById(R.id.chronometer);
        leftButton = (Button)findViewById(R.id.leftButton);
        rightButton = (Button)findViewById(R.id.rightButton);
        multiStopView = (ListView)findViewById(R.id.multiStopView);
        multiStopAdapter = new MultiStopAdapter(inflater);
        multiStopView.setAdapter(multiStopAdapter);
        multiStopView.addHeaderView(inflater.inflate(R.layout.list_item, null));
    }

    public void onLeftButtonClick(View view) {
        if (chronometer.isStarted()) {
            onStopClick();
        } else {
            onStartClick();
        }
    }

    public void onRightButtonClick(View view) {
        if (chronometer.isStarted()) {
            onCountClick();
        } else {
            onResetClick();
        }
    }

    private void onStopClick() {
        chronometer.stop();
        leftButton.setText(getString(R.string.start));
        rightButton.setText(getString(R.string.reset));
    }

    private void onStartClick() {
        chronometer.start();
        leftButton.setText(getString(R.string.stop));
        rightButton.setText(getString(R.string.count));
    }

    private void onCountClick() {
        multiStopAdapter.addStop(chronometer.getElapsed());
    }

    private void onResetClick() {
        chronometer.reset();
        multiStopAdapter.reset();
    }
}
