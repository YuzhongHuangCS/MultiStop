package org.pillowsky.multistop;

import android.content.Context;
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

    ArrayList<StopItem> itemList;
    LayoutInflater inflater;

    public MultiStopAdapter(Context context) {
        itemList = new ArrayList<StopItem>();
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
        ((TextView) view.findViewById(R.id.itemID)).setText(Integer.toString(index + 1));
        ((TextView) view.findViewById(R.id.itemTotalTime)).setText(item.totalTime);
        ((TextView) view.findViewById(R.id.itemAddTime)).setText(item.addTime);
        ((TextView) view.findViewById(R.id.itemLapTime)).setText(item.lapTime);

        return view;
    }

    public void addItem(long elapsed) {
        StopItem item = new StopItem();
        item.elapsed = elapsed;
        item.totalTime = Long.toString(elapsed);

        if (itemList.isEmpty()) {
            item.addTime = Long.toString(0);
            item.lapTime = Long.toString(elapsed);
        } else {
            item.addTime = Long.toString(itemList.get(0).elapsed - elapsed);
            item.lapTime = Long.toString(itemList.get(itemList.size() - 1).elapsed - elapsed);
        }

        itemList.add(item);
        notifyDataSetChanged();
    }

    public void reset() {
        itemList.clear();
        notifyDataSetChanged();
    }
}
