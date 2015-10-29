package org.pillowsky.multistop;

import android.content.Context;
import android.os.Handler;
import android.os.Message;
import android.os.SystemClock;
import android.text.format.DateUtils;
import android.util.AttributeSet;
import android.widget.TextView;

public class MilliChronometer extends TextView {
    private static final String TAG = "MilliChronometer";

    public interface OnMilliChronometerTickListener {
        void onChronometerTick(MilliChronometer milliChronometer);
    }

    private long mBase;
    private long mLast;
    private boolean mVisible;
    private boolean mStarted;
    private boolean mRunning;
    private OnMilliChronometerTickListener mOnMilliChronometerTickListener;
    private StringBuilder mRecycle = new StringBuilder(8);

    private static final int TICK_WHAT = 2;
    private static final int UPDATE_INTERVAL = 40;

    public MilliChronometer(Context context) {
        this(context, null, 0);
    }

    public MilliChronometer(Context context, AttributeSet attrs) {
        this(context, attrs, 0);
    }

    public MilliChronometer(Context context, AttributeSet attrs, int defStyle) {
        super(context, attrs, defStyle);
        init();
    }

    private void init() {
        mLast = mBase = SystemClock.elapsedRealtime();
        updateText(mBase);
    }

    public void setBase(long base) {
        mLast = mBase = base;
        dispatchChronometerTick();
        updateText(SystemClock.elapsedRealtime());
    }

    public long getBase() {
        return mBase;
    }

    public void setOnChronometerTickListener(OnMilliChronometerTickListener listener) {
        mOnMilliChronometerTickListener = listener;
    }

    public OnMilliChronometerTickListener getOnChronometerTickListener() {
        return mOnMilliChronometerTickListener;
    }

    public void start() {
        mBase += SystemClock.elapsedRealtime() - mLast;
        mStarted = true;
        updateRunning();
    }

    public void stop() {
        mStarted = false;
        mLast = SystemClock.elapsedRealtime();
        updateRunning();
    }

    public void reset() {
        init();
    }

    public void setStarted(boolean started) {
        mStarted = started;
        updateRunning();
    }

    public boolean isStarted() {
        return mStarted;
    }

    public long getElapsed() {
        return SystemClock.elapsedRealtime() - mBase;
    }

    @Override
    protected void onDetachedFromWindow() {
        super.onDetachedFromWindow();
        mVisible = false;
        updateRunning();
    }

    @Override
    protected void onWindowVisibilityChanged(int visibility) {
        super.onWindowVisibilityChanged(visibility);
        mVisible = visibility == VISIBLE;
        updateRunning();
    }

    private synchronized void updateText(long now) {
        setText(formatTime(now - mBase));
    }

    private void updateRunning() {
        boolean running = mVisible && mStarted;
        if (running != mRunning) {
            if (running) {
                updateText(SystemClock.elapsedRealtime());
                dispatchChronometerTick();
                mHandler.sendMessageDelayed(Message.obtain(mHandler, TICK_WHAT), UPDATE_INTERVAL);
            } else {
                mHandler.removeMessages(TICK_WHAT);
            }
            mRunning = running;
        }
    }

    private Handler mHandler = new Handler() {
        public void handleMessage(Message m) {
            if (mRunning) {
                updateText(SystemClock.elapsedRealtime());
                dispatchChronometerTick();
                sendMessageDelayed(Message.obtain(this , TICK_WHAT), UPDATE_INTERVAL);
            }
        }
    };

    private void dispatchChronometerTick() {
        if (mOnMilliChronometerTickListener != null) {
            mOnMilliChronometerTickListener.onChronometerTick(this);
        }
    }

    private String formatTime(long time) {
        return String.format("%s.%03d", DateUtils.formatElapsedTime(mRecycle, time / 1000), time % 1000);
    }
}
