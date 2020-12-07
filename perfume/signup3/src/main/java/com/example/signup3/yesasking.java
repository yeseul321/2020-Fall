package com.example.signup3;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;

public class yesasking extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_yesasking);

        Button woody = (Button)findViewById(R.id.woody);
        Button citrus = (Button)findViewById(R.id.citrus);
        Button fruity = (Button)findViewById(R.id.fruity);
        Button musk = (Button)findViewById(R.id.musk);
        Button oriental = (Button)findViewById(R.id.oriental);
        Button floral = (Button)findViewById(R.id.floral);

        woody.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {

                Intent intent = new Intent(yesasking.this, FinalAsking.class);

                intent.putExtra("perfume", "woody");

                startActivity(intent);
            }
        });

        citrus.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent(getApplicationContext(), FinalAsking.class);

                intent.putExtra("perfume", "citrus");

                startActivity(intent);
            }
        });

        fruity.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent(getApplicationContext(), FinalAsking.class);

                intent.putExtra("perfume", "fruity");

                startActivity(intent);
            }
        });

        musk.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent(getApplicationContext(), FinalAsking.class);

                intent.putExtra("perfume", "musk");

                startActivity(intent);
            }
        });

        oriental.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent(getApplicationContext(), FinalAsking.class);

                intent.putExtra("perfume", "oriental");

                startActivity(intent);
            }
        });

         floral.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent(getApplicationContext(), FinalAsking.class);

                intent.putExtra("perfume", "floral");

                startActivity(intent);
            }
        });
    }
}