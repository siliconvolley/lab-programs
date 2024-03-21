package com.example.parser_app;

import androidx.appcompat.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.TextView;
import android.widget.Toast;
import org.json.JSONArray;
import org.json.JSONObject;
import org.w3c.dom.Document;
import org.w3c.dom.Element;
import org.w3c.dom.Node;
import org.w3c.dom.NodeList;
import java.io.InputStream;
import java.nio.charset.StandardCharsets;
import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;

public class MainActivity extends AppCompatActivity {
    TextView display;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        display = findViewById(R.id.display);
    }

    public void parsexml(View V) {
        try {
            InputStream is = getAssets().open("city.xml");
            DocumentBuilderFactory documentBuilderFactory = DocumentBuilderFactory.newInstance();
            DocumentBuilder documentBuilder = documentBuilderFactory.newDocumentBuilder();
            Document document = documentBuilder.parse(is);
            StringBuilder stringBuilder = new StringBuilder();
            stringBuilder.append("XML DATA");
            stringBuilder.append("\n-----------");
            NodeList nodeList = document.getElementsByTagName("place");
            for (int i = 0; i < nodeList.getLength(); i++) {
                Node node = nodeList.item(i);
                if (node.getNodeType() == Node.ELEMENT_NODE) {
                    Element element = (Element) node;
                    stringBuilder.append("\nName: ").append(getValue("name", element));
                    stringBuilder.append("\nlat: ").append(getValue("lat", element));
                    stringBuilder.append("\nLong: ").append(getValue("long", element));
                    stringBuilder.append("\nTemperature: ").append(getValue("temperature", element));
                    stringBuilder.append("\nHumidity: ").append(getValue("humidity", element));
                    stringBuilder.append("\n----------");
                }
            }
            display.setText(stringBuilder.toString());
        } catch (Exception e) {
            e.printStackTrace();
            Toast.makeText(MainActivity.this, "Error in reading XML", Toast.LENGTH_LONG).show();
        }
    }

    public void parsejson(View V) {
        String json;
        StringBuilder stringBuilder = new StringBuilder();
        try {
            InputStream is = getAssets().open("city.json");
            int size = is.available();
            byte[] buffer = new byte[size];
            is.read(buffer);
            json = new String(buffer, StandardCharsets.UTF_8);
            JSONArray jsonArray = new JSONArray(json);
            stringBuilder.append("JSON Data");
            stringBuilder.append("\n----------");
            for (int i = 0; i < jsonArray.length(); i++) {
                JSONObject jsonObject = jsonArray.getJSONObject(i);
                stringBuilder.append("\nName: ").append(jsonObject.getString("name"));
                stringBuilder.append("\nlat: ").append(jsonObject.getString("lat"));
                stringBuilder.append("\nlong: ").append(jsonObject.getString("long"));
                stringBuilder.append("\ntemperature: ").append(jsonObject.getString("temperature"));
                stringBuilder.append("\nhumdity: ").append(jsonObject.getString("humidity"));
                stringBuilder.append("\n------------");
            }
            display.setText(stringBuilder.toString());
            is.close();
        } catch (Exception e) {
            e.printStackTrace();
            Toast.makeText(MainActivity.this, "Error in reading JSON file",
                    Toast.LENGTH_LONG).show();
        }
    }

    private String getValue(String tag, Element element) {
        return element.getElementsByTagName(tag).item(0).getChildNodes().item(0).getNodeValue();
    }
}