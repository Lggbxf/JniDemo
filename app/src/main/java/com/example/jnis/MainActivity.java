package com.example.jnis;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ImageView;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity implements View.OnClickListener {

    private Button button,btn_encode,btn_change,btn_paint;
    private TextView textView;
    private EditText et_msg;
    private ImageView iv_photo;
    private int[] arr = {2,9,5,6,7,3};
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        initView();
        initData();
    }

    private void initView() {
        textView = findViewById(R.id.tv);
        et_msg = findViewById(R.id.et_msg);
        iv_photo = findViewById(R.id.iv_photo);
        btn_encode = findViewById(R.id.btn_encode);
        button = findViewById(R.id.btn);
        btn_change = findViewById(R.id.btn_change);
        btn_paint = findViewById(R.id.btn_paint);
        btn_encode.setOnClickListener(this);
        button.setOnClickListener(this);
        btn_change.setOnClickListener(this);
        btn_paint.setOnClickListener(this);
    }

    private void initData() {
        iv_photo.setImageResource(R.mipmap.timg);
    }

    private void paint(){

    }

    @Override
    public void onClick(View v) {
        switch (v.getId()){
            case R.id.btn:
                textView.setText(JniUtils.getString()+JniUtils.getAddResult(1,6));
                break;
            case R.id.btn_encode:
                String msg = et_msg.getText().toString().trim();
                et_msg.setText(JniUtils.encode(msg));
                break;
            case R.id.btn_change:
                int[] new_arr = JniUtils.changeToArray(arr);
                for (int i =0;i<new_arr.length;i++){
                    Log.i("MainActivity","new_arr:"+new_arr[i]);
                }
                break;
            case R.id.btn_paint:

                break;
        }
    }
}
