package org.pillowsky.multistop;

import android.content.Context;
import android.text.format.DateUtils;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseAdapter;
import android.widget.TextView;

import java.util.ArrayList;

public class MultiStopAdapter extends BaseAdapter {
    class StopItem {
        long elapsed;
        String totalTime;
        String addTime;
        String lapTime;
    }

    private LayoutInflater inflater;
    private ArrayList<StopItem> itemList = new ArrayList<StopItem>();
    private StringBuilder mRecycle = new StringBuilder(8);

    public MultiStopAdapter(Context context) {
        inflater = (LayoutInflater)context.getSystemService(Context.LAYOUT_INFLATER_SERVICE);
    }

    @Override
    public int getCount() {
        return itemList.size();
    }

    @Override
    public Object getItem(int index) {
        return itemList.get(index);
    }

    @Override
    public long getItemId(int index) {
        return index;
    }

    @Override
    public View getView(int index, View view, ViewGroup parent) {
        if (view == null) {
            view = inflater.inflate(R.layout.list_item, parent, false);
        }

        StopItem item = itemList.get(index);
        ((TextView)view.findViewById(R.id.itemID)).setText(String.format("%d:", index + 1));
        ((TextView)view.findViewById(R.id.itemTotalTime)).setText(item.totalTime);
        ((TextView)view.findViewById(R.id.itemAddTime)).setText(item.addTime);
        ((TextView)view.findViewById(R.id.itemLapTime)).setText(item.lapTime);

        return view;
    }

    public void addStop(long elapsed) {
        StopItem item = new StopItem();
        item.elapsed = elapsed;
        item.totalTime = formatTime(elapsed);

        if (itemList.isEmpty()) {
            item.addTime = Long.toString(0);
            item.lapTime = formatTime(elapsed);
        } else {
            item.addTime = formatTime(elapsed - itemList.get(0).elapsed);
            item.lapTime = formatTime(elapsed - itemList.get(itemList.size() - 1).elapsed);
        }

        itemList.add(item);
        notifyDataSetChanged();
    }

    public void reset() {
        itemList.clear();
        notifyDataSetChanged();
    }

    private String formatTime(long time) {
        return String.format("%s.%03d", DateUtils.formatElapsedTime(mRecycle, time / 1000), time % 1000);
    }
}
