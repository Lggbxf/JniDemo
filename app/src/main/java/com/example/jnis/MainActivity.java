package com.example.jnis;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity implements View.OnClickListener {

    private Button button,btn_encode;
    private TextView textView;
    private EditText et_msg;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        textView = findViewById(R.id.tv);
        et_msg = findViewById(R.id.et_msg);
        btn_encode = findViewById(R.id.btn_encode);
        button = findViewById(R.id.btn);
        btn_encode.setOnClickListener(this);
        button.setOnClickListener(this);
//        button.setOnClickListener(new View.OnClickListener() {
//            @Override
//            public void onClick(View v) {
//
//                textView.setText(JniUtils.getString()+JniUtils.getAddResult(1,6));
//            }
//        });
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
        }
    }
}
