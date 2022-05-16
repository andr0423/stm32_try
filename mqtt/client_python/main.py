from json import JSONDecodeError

import paho.mqtt.client as mqtt
import sqlite3
import json
import datetime


# TODO check table, create if needed
con = sqlite3.connect("mqtt.sqlite")
cur = con.cursor()


def on_connect(client, userdata, flags, rc):
    print("Connected with result code "+str(rc))


def on_message(client, userdata, msg):
    print(msg.topic+" "+str(msg.payload))
    try:
        j = json.loads(str(msg.payload).strip("b\'"))
        if "date" in j and len(str(j["date"])) == 10 and isinstance(j["date"], int):
            dt = j["date"]
        else:
            dt = int(datetime.datetime.timestamp(datetime.datetime.now()))
        sql = f'insert into mqtt ("t", "p", "h", "date") values({j["t"]},{j["p"]},{j["h"]},{dt})'
        cur.execute(sql)
        con.commit()
        print('Ok')
    except JSONDecodeError:
        print("Incorrect msg format")
    except Exception:
        print("An error")


client = mqtt.Client()
client.on_connect = on_connect
client.on_message = on_message
client.connect("127.0.0.1")
client.subscribe("vkr_topic")

client.loop_forever()

