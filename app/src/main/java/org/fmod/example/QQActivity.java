package org.fmod.example;

import android.os.Environment;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;

import com.example.shengqi.R;

import org.fmod.FMOD;

import java.io.File;

public class QQActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        FMOD.init(this);
        setContentView(R.layout.activity_qq);
    }

    public void mFix(View btn) {
        String path = Environment.getExternalStorageDirectory().getAbsolutePath() + File.separatorChar + "drumloop.wav";

        switch (btn.getId()) {
            case R.id.btn_normal://
                EffectUtis.fix(path, EffectUtis.MODE_NORMAL);
                break;

            case R.id.btn_luoli:
                EffectUtis.fix(path, EffectUtis.MODE_LUOLI);
                break;
            case R.id.btn_dashu:
                EffectUtis.fix(path, EffectUtis.MODE_DASHU);
                break;

            case R.id.btn_jingsong:
                EffectUtis.fix(path, EffectUtis.MODE_JINGSONG);
                break;

            case R.id.btn_gaoguai:
                EffectUtis.fix(path, EffectUtis.MODE_GAOGUAI);
                break;

            case R.id.btn_kongling:
                EffectUtis.fix(path, EffectUtis.MODE_KONGLING);
                break;
        }
    }

    @Override
    protected void onDestroy() {
        super.onDestroy();
        FMOD.close();
    }
}
