<h1>EPIoT</h1>
<h2>IoT para controle de uso de EPIs em um ambiente organizacional seguro</h1>
Utilizamos ESP32 e um sensor de movimento onde detectamos se está em movimento (em uso) ou parado (sem uso) determinado EPI. 
O protocolo utilizado é o MQTT. 
Para armazenar o historico do sensor, utilizamos um banco de dados MySql.


<h3>Simulação Wokwi</h3>
https://wokwi.com/projects/410862935651732481

![image](https://github.com/user-attachments/assets/eeca3246-a096-444f-b9c5-112c2fdca6c8)



<h3>NodeRed</h3>
http://18.228.117.52:1880/#flow/7c73a53ef8e5a4e3
http://18.228.117.52:1880/ui

Sensor em movimento
mosquitto_pub -h 18.228.117.52 -t "sensor/movimento" -m "1" -u "USER" -P "PASS"

![image](https://github.com/user-attachments/assets/ea05d312-6598-47f9-8ff1-750175bb4996)


Sensor parado
mosquitto_pub -h 18.228.117.52 -t "sensor/movimento" -m "0" -u "USER" -P "PASS"

![image](https://github.com/user-attachments/assets/8a451ece-3a03-4552-8812-a3bac84b08bc)

