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

Senso parado
mosquitto_pub -h 18.228.117.52 -t "sensor/movimento" -m "0" -u "USER" -P "PASS"
![image](https://github.com/user-attachments/assets/27a0defc-619d-49f4-b637-377c00fb57bf)

Sensor em movimento
mosquitto_pub -h 18.228.117.52 -t "sensor/movimento" -m "1" -u "USER" -P "PASS"
![image](https://github.com/user-attachments/assets/8b40baa3-27c4-46e8-a425-87e56749128b)

