<h1>Criação de um IoT para capturar movimentos e enviar via MQTT no node-red.</h1>


Link NodeRed
http://18.228.117.52:1880/#flow/7c73a53ef8e5a4e3

http://18.228.117.52:1880/ui/#!/0?socketid=4lFPzb4rPUsNemY8AAAA

Sensor em movimento
mosquitto_pub -h 18.228.117.52 -t "sensor/movimento" -m "1" -u "USER" -P "PASS"

![image](https://github.com/user-attachments/assets/ea05d312-6598-47f9-8ff1-750175bb4996)


Sensor parado
mosquitto_pub -h 18.228.117.52 -t "sensor/movimento" -m "0" -u "USER" -P "PASS"

![image](https://github.com/user-attachments/assets/8a451ece-3a03-4552-8812-a3bac84b08bc)

