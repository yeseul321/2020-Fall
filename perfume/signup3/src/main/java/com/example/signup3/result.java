package com.example.signup3;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.widget.Toast;

public class result extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_result);

        Intent intent = getIntent();

        String scent1 = intent.getStringExtra("scent1");
        String scent2 = intent.getStringExtra("scent2");

        Toast.makeText(getApplicationContext(), "선택한 향료는 "+ scent1 +"와 "+ scent2, Toast.LENGTH_SHORT).show();
    }
}