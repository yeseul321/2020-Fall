package com.example.signup3;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.Spinner;
import android.widget.Toast;

import com.google.android.gms.tasks.OnCompleteListener;
import com.google.android.gms.tasks.Task;
import com.google.firebase.auth.FirebaseAuth;
import com.google.firebase.auth.FirebaseUser;
import com.google.firebase.auth.UserProfileChangeRequest;
import com.google.firebase.database.DatabaseReference;
import com.google.firebase.database.FirebaseDatabase;

import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.HashMap;

public class FinalAsking extends AppCompatActivity {

    Spinner spinner1;
    Spinner spinner2;
    String s1;
    String s2;


    FirebaseUser user = FirebaseAuth.getInstance().getCurrentUser();
    FirebaseDatabase database = FirebaseDatabase.getInstance();
    DatabaseReference reference = database.getReference("Users");


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_final_asking);

        spinner1 = (Spinner)findViewById(R.id.spinner1);
        spinner2 = (Spinner)findViewById(R.id.spinner2);

        Button button = (Button)findViewById(R.id.spinnerbutton);

        Intent intent = getIntent();

        String perfume = intent.getStringExtra("perfume");

        if(perfume.equals("woody")) {
            ArrayAdapter arrayAdapter = ArrayAdapter.createFromResource(this, R.array.woody, android.R.layout.simple_spinner_dropdown_item);
            arrayAdapter.setDropDownViewResource(android.R.layout.simple_spinner_dropdown_item);
            spinner1.setAdapter(arrayAdapter);
            spinner2.setAdapter(arrayAdapter);
            spinner1.setOnItemSelectedListener(new AdapterView.OnItemSelectedListener() {
                @Override
                public void onItemSelected(AdapterView<?> parent, View view, int position, long id) {
                    Toast.makeText(getApplicationContext(), parent.getItemAtPosition(position) + "(이)가 선택되었습니다.", Toast.LENGTH_SHORT).show();
                    s1 = parent.getItemAtPosition(position).toString();
                }

                @Override
                public void onNothingSelected(AdapterView<?> parent) {

                }
            });
            spinner2.setOnItemSelectedListener(new AdapterView.OnItemSelectedListener() {
                @Override
                public void onItemSelected(AdapterView<?> parent, View view, int position, long id) {
                    Toast.makeText(getApplicationContext(), parent.getItemAtPosition(position) + "(이)가 선택되었습니다.", Toast.LENGTH_SHORT).show();
                    s2 = parent.getItemAtPosition(position).toString();
                }

                @Override
                public void onNothingSelected(AdapterView<?> parent) {
                }
            });
        }
        else if(perfume.equals("floral")){
            ArrayAdapter arrayAdapter = ArrayAdapter.createFromResource(this, R.array.floral, android.R.layout.simple_spinner_dropdown_item);
            arrayAdapter.setDropDownViewResource(android.R.layout.simple_spinner_dropdown_item);
            spinner1.setAdapter(arrayAdapter);
            spinner2.setAdapter(arrayAdapter);
            spinner1.setOnItemSelectedListener(new AdapterView.OnItemSelectedListener() {
                @Override
                public void onItemSelected(AdapterView<?> parent, View view, int position, long id) {
                    Toast.makeText(getApplicationContext(), parent.getItemAtPosition(position) + "(이)가 선택되었습니다.", Toast.LENGTH_SHORT).show();
                    s1 = parent.getItemAtPosition(position).toString();
                }

                @Override
                public void onNothingSelected(AdapterView<?> parent) {

                }
            });
            spinner2.setOnItemSelectedListener(new AdapterView.OnItemSelectedListener() {
                @Override
                public void onItemSelected(AdapterView<?> parent, View view, int position, long id) {
                    Toast.makeText(getApplicationContext(), parent.getItemAtPosition(position) + "(이)가 선택되었습니다.", Toast.LENGTH_SHORT).show();
                    s2 = parent.getItemAtPosition(position).toString();
                }

                @Override
                public void onNothingSelected(AdapterView<?> parent) {

                }
            });
        }

        else if(perfume.equals("oriental")){
            ArrayAdapter arrayAdapter = ArrayAdapter.createFromResource(this, R.array.oriental, android.R.layout.simple_spinner_dropdown_item);
            arrayAdapter.setDropDownViewResource(android.R.layout.simple_spinner_dropdown_item);
            spinner1.setAdapter(arrayAdapter);
            spinner2.setAdapter(arrayAdapter);
            spinner1.setOnItemSelectedListener(new AdapterView.OnItemSelectedListener() {
                @Override
                public void onItemSelected(AdapterView<?> parent, View view, int position, long id) {
                    Toast.makeText(getApplicationContext(), parent.getItemAtPosition(position) + "(이)가 선택되었습니다.", Toast.LENGTH_SHORT).show();
                    s1 = parent.getItemAtPosition(position).toString();
                }

                @Override
                public void onNothingSelected(AdapterView<?> parent) {

                }
            });
            spinner2.setOnItemSelectedListener(new AdapterView.OnItemSelectedListener() {
                @Override
                public void onItemSelected(AdapterView<?> parent, View view, int position, long id) {
                    Toast.makeText(getApplicationContext(), parent.getItemAtPosition(position) + "(이)가 선택되었습니다.", Toast.LENGTH_SHORT).show();
                    s2 = parent.getItemAtPosition(position).toString();
                }

                @Override
                public void onNothingSelected(AdapterView<?> parent) {

                }
            });
        }
        else if(perfume.equals("fruity")){
            ArrayAdapter arrayAdapter = ArrayAdapter.createFromResource(this, R.array.fruity, android.R.layout.simple_spinner_dropdown_item);
            arrayAdapter.setDropDownViewResource(android.R.layout.simple_spinner_dropdown_item);
            spinner1.setAdapter(arrayAdapter);
            spinner2.setAdapter(arrayAdapter);
            spinner1.setOnItemSelectedListener(new AdapterView.OnItemSelectedListener() {
                @Override
                public void onItemSelected(AdapterView<?> parent, View view, int position, long id) {
                    Toast.makeText(getApplicationContext(), parent.getItemAtPosition(position) + "(이)가 선택되었습니다.", Toast.LENGTH_SHORT).show();
                    s1 = parent.getItemAtPosition(position).toString();
                }

                @Override
                public void onNothingSelected(AdapterView<?> parent) {

                }
            });
            spinner2.setOnItemSelectedListener(new AdapterView.OnItemSelectedListener() {
                @Override
                public void onItemSelected(AdapterView<?> parent, View view, int position, long id) {
                    Toast.makeText(getApplicationContext(), parent.getItemAtPosition(position) + "(이)가 선택되었습니다.", Toast.LENGTH_SHORT).show();
                    s2 = parent.getItemAtPosition(position).toString();
                }

                @Override
                public void onNothingSelected(AdapterView<?> parent) {

                }
            });
        }

        else if(perfume.equals("citrus")){
            ArrayAdapter arrayAdapter = ArrayAdapter.createFromResource(this, R.array.citrus, android.R.layout.simple_spinner_dropdown_item);
            arrayAdapter.setDropDownViewResource(android.R.layout.simple_spinner_dropdown_item);
            spinner1.setAdapter(arrayAdapter);
            spinner2.setAdapter(arrayAdapter);
            spinner1.setOnItemSelectedListener(new AdapterView.OnItemSelectedListener() {
                @Override
                public void onItemSelected(AdapterView<?> parent, View view, int position, long id) {
                    Toast.makeText(getApplicationContext(), parent.getItemAtPosition(position) + "(이)가 선택되었습니다.", Toast.LENGTH_SHORT).show();
                    s1 = parent.getItemAtPosition(position).toString();
                }

                @Override
                public void onNothingSelected(AdapterView<?> parent) {

                }
            });
            spinner2.setOnItemSelectedListener(new AdapterView.OnItemSelectedListener() {
                @Override
                public void onItemSelected(AdapterView<?> parent, View view, int position, long id) {
                    Toast.makeText(getApplicationContext(), parent.getItemAtPosition(position) + "(이)가 선택되었습니다.", Toast.LENGTH_SHORT).show();
                    s2 = parent.getItemAtPosition(position).toString();
                }

                @Override
                public void onNothingSelected(AdapterView<?> parent) {

                }
            });
        }

        else if(perfume.equals("musk")){
            ArrayAdapter arrayAdapter = ArrayAdapter.createFromResource(this, R.array.musk, android.R.layout.simple_spinner_dropdown_item);
            arrayAdapter.setDropDownViewResource(android.R.layout.simple_spinner_dropdown_item);
            spinner1.setAdapter(arrayAdapter);
            spinner2.setAdapter(arrayAdapter);
            spinner1.setOnItemSelectedListener(new AdapterView.OnItemSelectedListener() {
                @Override
                public void onItemSelected(AdapterView<?> parent, View view, int position, long id) {
                    Toast.makeText(getApplicationContext(), parent.getItemAtPosition(position) + "(이)가 선택되었습니다.", Toast.LENGTH_SHORT).show();
                    s1 = parent.getItemAtPosition(position).toString();
                }

                @Override
                public void onNothingSelected(AdapterView<?> parent) {

                }
            });
            spinner2.setOnItemSelectedListener(new AdapterView.OnItemSelectedListener() {
                @Override
                public void onItemSelected(AdapterView<?> parent, View view, int position, long id) {
                    Toast.makeText(getApplicationContext(), parent.getItemAtPosition(position) + "(이)가 선택되었습니다.", Toast.LENGTH_SHORT).show();
                    s2 = parent.getItemAtPosition(position).toString();
                }

                @Override
                public void onNothingSelected(AdapterView<?> parent) {

                }
            });
        }

        button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {

                HashMap<Object,String> hashMap = new HashMap<>();

                String name = user.getDisplayName();
                String email = user.getEmail();

                hashMap.put("name", name);
                hashMap.put("email", email);
                hashMap.put("scent1",s1);
                hashMap.put("scent2",s2);

                String uid = user.getUid();

                reference.child(uid).setValue(hashMap);

                Intent intent = new Intent(FinalAsking.this, result.class);

                intent.putExtra("scent1", s1);
                intent.putExtra("scent2", s2);

                startActivity(intent);
            }
        });


    }
}