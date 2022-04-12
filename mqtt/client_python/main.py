import paho.mqtt.client as mqtt
import sqlite3
import json

# TODO check table, create if needed
con = sqlite3.connect("mqtt.sqlite")
cur = con.cursor()


def on_connect(client, userdata, flags, rc):
    print("Connected with result code "+str(rc))


def on_message(client, userdata, msg):
    print(msg.topic+" "+str(msg.payload))
    j = json.loads(str(msg.payload).strip("b\'"))
    sql = f'insert into mqtt ("t", "p", "h", "date") values({j["t"]},{j["p"]},{j["h"]}, 123)'
    cur.execute(sql)
    con.commit()
    pass


client = mqtt.Client()
client.on_connect = on_connect
client.on_message = on_message
client.connect("127.0.0.1")
client.subscribe("test")

client.loop_forever()

