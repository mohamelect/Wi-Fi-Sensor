#include "json_config.h"


bool JsonConf::saveConfig() {
  StaticJsonBuffer<1024> jsonBuffer;
#ifdef DEBUG_JSON_CONFIG
  Serial.print(F("saveConfig()"));  Serial.println();
#endif

  JsonObject& json = jsonBuffer.createObject();


  json["module_id"]                     = module_id                    ;                           
  json["sta_ssid"]                      = sta_ssid                     ;                         
  json["sta_pwd"]                       = sta_pwd                      ;                       
  json["static_ip_mode"]                = static_ip_mode               ;                                     
  json["static_ip"]                     = static_ip                    ;                           
  json["static_gateway"]                = static_gateway               ;                                     
  json["static_subnet"]                 = static_subnet                ;                                   
  json["ntp_server"]                    = ntp_server                   ;                             
  json["my_time_zone"]                  = my_time_zone                 ;                           
  json["mqtt_server"]                   = mqtt_server                  ;                               
  json["mqtt_port"]                     = mqtt_port                    ;                           
  json["mqtt_user"]                     = mqtt_user                    ;                           
  json["mqtt_pwd"]                      = mqtt_pwd                     ;                         
  json["mqtt_name"]                     = mqtt_name                    ;                           
  json["publish_topic"]                 = publish_topic                ;                                   
  json["subscribe_topic"]               = subscribe_topic              ;                                       
  json["command_pub_topic"]             = command_pub_topic            ;                                           
  json["light_pin"]                     = light_pin                    ;                           
  json["lightoff_delay"]                = lightoff_delay               ;                                     
  json["light_pin2"]                    = light_pin2                   ;                             
  json["light2off_delay"]               = light2off_delay              ;                                       
  json["motion_pin"]                    = motion_pin                   ;                             
  json["dht_pin"]                       = dht_pin                      ;                       
  json["get_data_delay"]                = get_data_delay               ;                                     
  json["publish_delay"]                 = publish_delay                ;                                   
  json["subscribe_delay"]               = subscribe_delay              ;                                       
  json["motion_read_delay"]             = motion_read_delay            ;                                           
  json["reboot_delay"]                  = reboot_delay                 ;                                 
  json["uart_delay_analog_pin0"]        = uart_delay_analog_pin0       ;                                                     
  json["uart_delay_analog_pin1"]        = uart_delay_analog_pin1       ;                                                     
  json["uart_delay_analog_pin2"]        = uart_delay_analog_pin2       ;                                                     
  json["uart_delay_analog_pin3"]        = uart_delay_analog_pin3       ;                                                     
  json["uart_delay_analog_pin4"]        = uart_delay_analog_pin4       ;                                                     
  json["uart_delay_analog_pin5"]        = uart_delay_analog_pin5       ;                                                     
  json["green_light_on"]                = green_light_on               ;                                     
  json["green_light_off"]               = green_light_off              ;                                       
  json["green_light_pin"]               = green_light_pin              ;                                       
  json["green_humidity_threshold_up"]   = green_humidity_threshold_up  ;                                                               
  json["green_humidity_threshold_down"] = green_humidity_threshold_down;                                                                   
  json["green_humidity_sensor_pin"]     = green_humidity_sensor_pin    ;                                                           
  json["green_pump_pin"]                = green_pump_pin               ;                                     


  File configFile = SPIFFS.open("/config.json", "w");
  if (!configFile) {
#ifdef DEBUG_JSON_CONFIG
    Serial.println(F("Failed to open config file for writing"));
#endif
    return false;
  }
#ifdef DEBUG_JSON_CONFIG
  Serial.println();
  json.printTo(Serial);
  Serial.println();
#endif
  json.printTo(configFile);
  configFile.close();
  return true;
}


bool JsonConf::loadConfig() {
#ifdef DEBUG_JSON_CONFIG
  Serial.print(F("loadConfig()"));  Serial.println();
#endif

  File configFile = SPIFFS.open("/config.json", "r");
  if (!configFile) {
#ifdef DEBUG_JSON_CONFIG
    Serial.println(F("Failed to open config file"));
    saveConfig();
#endif
    return false;
  }

  size_t size = configFile.size();
  if (size > 2048) {
#ifdef DEBUG_JSON_CONFIG
    Serial.println(F("Config file size is too large"));
    SPIFFS.remove("/config.json");
    saveConfig();
#endif
    return false;
  }

  // Allocate a buffer to store contents of the file.
  std::unique_ptr<char[]> buf(new char[size]);

  // We don't use String here because ArduinoJson library requires the input
  // buffer to be mutable. If you don't use ArduinoJson, you may as well
  // use configFile.readString instead.
  configFile.readBytes(buf.get(), size);

  StaticJsonBuffer<1024> jsonBuffer;
  JsonObject& json = jsonBuffer.parseObject(buf.get());

  if (!json.success()) {
#ifdef DEBUG_JSON_CONFIG
    Serial.println(F("Failed to parse config file"));
    SPIFFS.remove("/config.json");
    saveConfig();
#endif
    return false;
  }
  const char* null_str = "<null>";

  const char* module_id_char                     = json["module_id"                    ];    if (memcmp (&module_id_char                    , &null_str,6)==0) SPIFFS.remove("/config.json"); saveConfig();   sprintf_P(module_id,                     ("%s"), module_id_char                    );
  const char* sta_ssid_char                      = json["sta_ssid"                     ];    if (memcmp (&sta_ssid_char                     , &null_str,6)==0) SPIFFS.remove("/config.json"); saveConfig();   sprintf_P(sta_ssid,                      ("%s"), sta_ssid_char                     );
  const char* sta_pwd_char                       = json["sta_pwd"                      ];    if (memcmp (&sta_pwd_char                      , &null_str,6)==0) SPIFFS.remove("/config.json"); saveConfig();   sprintf_P(sta_pwd,                       ("%s"), sta_pwd_char                      );
  const char* static_ip_mode_char                = json["static_ip_mode"               ];    if (memcmp (&static_ip_mode_char               , &null_str,6)==0) SPIFFS.remove("/config.json"); saveConfig();   sprintf_P(static_ip_mode,                ("%s"), static_ip_mode_char               );
  const char* static_ip_char                     = json["static_ip"                    ];    if (memcmp (&static_ip_char                    , &null_str,6)==0) SPIFFS.remove("/config.json"); saveConfig();   sprintf_P(static_ip,                     ("%s"), static_ip_char                    );
  const char* static_gateway_char                = json["static_gateway"               ];    if (memcmp (&static_gateway_char               , &null_str,6)==0) SPIFFS.remove("/config.json"); saveConfig();   sprintf_P(static_gateway,                ("%s"), static_gateway_char               );
  const char* static_subnet_char                 = json["static_subnet"                ];    if (memcmp (&static_subnet_char                , &null_str,6)==0) SPIFFS.remove("/config.json"); saveConfig();   sprintf_P(static_subnet,                 ("%s"), static_subnet_char                );
  const char* ntp_server_char                    = json["ntp_server"                   ];    if (memcmp (&ntp_server_char                   , &null_str,6)==0) SPIFFS.remove("/config.json"); saveConfig();   sprintf_P(ntp_server,                    ("%s"), ntp_server_char                   );
  const char* my_time_zone_char                  = json["my_time_zone"                 ];    if (memcmp (&my_time_zone_char                 , &null_str,6)==0) SPIFFS.remove("/config.json"); saveConfig();   sprintf_P(my_time_zone,                  ("%s"), my_time_zone_char                 );
  const char* mqtt_server_char                   = json["mqtt_server"                  ];    if (memcmp (&mqtt_server_char                  , &null_str,6)==0) SPIFFS.remove("/config.json"); saveConfig();   sprintf_P(mqtt_server,                   ("%s"), mqtt_server_char                  );
  const char* mqtt_port_char                     = json["mqtt_port"                    ];    if (memcmp (&mqtt_port_char                    , &null_str,6)==0) SPIFFS.remove("/config.json"); saveConfig();   sprintf_P(mqtt_port,                     ("%s"), mqtt_port_char                    );
  const char* mqtt_user_char                     = json["mqtt_user"                    ];    if (memcmp (&mqtt_user_char                    , &null_str,6)==0) SPIFFS.remove("/config.json"); saveConfig();   sprintf_P(mqtt_user,                     ("%s"), mqtt_user_char                    );
  const char* mqtt_pwd_char                      = json["mqtt_pwd"                     ];    if (memcmp (&mqtt_pwd_char                     , &null_str,6)==0) SPIFFS.remove("/config.json"); saveConfig();   sprintf_P(mqtt_pwd,                      ("%s"), mqtt_pwd_char                     );
  const char* mqtt_name_char                     = json["mqtt_name"                    ];    if (memcmp (&mqtt_name_char                    , &null_str,6)==0) SPIFFS.remove("/config.json"); saveConfig();   sprintf_P(mqtt_name,                     ("%s"), mqtt_name_char                    );
  const char* publish_topic_char                 = json["publish_topic"                ];    if (memcmp (&publish_topic_char                , &null_str,6)==0) SPIFFS.remove("/config.json"); saveConfig();   sprintf_P(publish_topic,                 ("%s"), publish_topic_char                );
  const char* subscribe_topic_char               = json["subscribe_topic"              ];    if (memcmp (&subscribe_topic_char              , &null_str,6)==0) SPIFFS.remove("/config.json"); saveConfig();   sprintf_P(subscribe_topic,               ("%s"), subscribe_topic_char              );
  const char* command_pub_topic_char             = json["command_pub_topic"            ];    if (memcmp (&command_pub_topic_char            , &null_str,6)==0) SPIFFS.remove("/config.json"); saveConfig();   sprintf_P(command_pub_topic,             ("%s"), command_pub_topic_char            );
  const char* light_pin_char                     = json["light_pin"                    ];    if (memcmp (&light_pin_char                    , &null_str,6)==0) SPIFFS.remove("/config.json"); saveConfig();   sprintf_P(light_pin,                     ("%s"), light_pin_char                    );
  const char* lightoff_delay_char                = json["lightoff_delay"               ];    if (memcmp (&lightoff_delay_char               , &null_str,6)==0) SPIFFS.remove("/config.json"); saveConfig();   sprintf_P(lightoff_delay,                ("%s"), lightoff_delay_char               );
  const char* light_pin2_char                    = json["light_pin2"                   ];    if (memcmp (&light_pin2_char                   , &null_str,6)==0) SPIFFS.remove("/config.json"); saveConfig();   sprintf_P(light_pin2,                    ("%s"), light_pin2_char                   );
  const char* light2off_delay_char               = json["light2off_delay"              ];    if (memcmp (&light2off_delay_char              , &null_str,6)==0) SPIFFS.remove("/config.json"); saveConfig();   sprintf_P(light2off_delay,               ("%s"), light2off_delay_char              );
  const char* motion_pin_char                    = json["motion_pin"                   ];    if (memcmp (&motion_pin_char                   , &null_str,6)==0) SPIFFS.remove("/config.json"); saveConfig();   sprintf_P(motion_pin,                    ("%s"), motion_pin_char                   );
  const char* dht_pin_char                       = json["dht_pin"                      ];    if (memcmp (&dht_pin_char                      , &null_str,6)==0) SPIFFS.remove("/config.json"); saveConfig();   sprintf_P(dht_pin,                       ("%s"), dht_pin_char                      );
  const char* get_data_delay_char                = json["get_data_delay"               ];    if (memcmp (&get_data_delay_char               , &null_str,6)==0) SPIFFS.remove("/config.json"); saveConfig();   sprintf_P(get_data_delay,                ("%s"), get_data_delay_char               );
  const char* publish_delay_char                 = json["publish_delay"                ];    if (memcmp (&publish_delay_char                , &null_str,6)==0) SPIFFS.remove("/config.json"); saveConfig();   sprintf_P(publish_delay,                 ("%s"), publish_delay_char                );
  const char* subscribe_delay_char               = json["subscribe_delay"              ];    if (memcmp (&subscribe_delay_char              , &null_str,6)==0) SPIFFS.remove("/config.json"); saveConfig();   sprintf_P(subscribe_delay,               ("%s"), subscribe_delay_char              );
  const char* motion_read_delay_char             = json["motion_read_delay"            ];    if (memcmp (&motion_read_delay_char            , &null_str,6)==0) SPIFFS.remove("/config.json"); saveConfig();   sprintf_P(motion_read_delay,             ("%s"), motion_read_delay_char            );
  const char* reboot_delay_char                  = json["reboot_delay"                 ];    if (memcmp (&reboot_delay_char                 , &null_str,6)==0) SPIFFS.remove("/config.json"); saveConfig();   sprintf_P(reboot_delay,                  ("%s"), reboot_delay_char                 );
  const char* uart_delay_analog_pin0_char        = json["uart_delay_analog_pin0"       ];    if (memcmp (&uart_delay_analog_pin0_char       , &null_str,6)==0) SPIFFS.remove("/config.json"); saveConfig();   sprintf_P(uart_delay_analog_pin0,        ("%s"), uart_delay_analog_pin0_char       );
  const char* uart_delay_analog_pin1_char        = json["uart_delay_analog_pin1"       ];    if (memcmp (&uart_delay_analog_pin1_char       , &null_str,6)==0) SPIFFS.remove("/config.json"); saveConfig();   sprintf_P(uart_delay_analog_pin1,        ("%s"), uart_delay_analog_pin1_char       );
  const char* uart_delay_analog_pin2_char        = json["uart_delay_analog_pin2"       ];    if (memcmp (&uart_delay_analog_pin2_char       , &null_str,6)==0) SPIFFS.remove("/config.json"); saveConfig();   sprintf_P(uart_delay_analog_pin2,        ("%s"), uart_delay_analog_pin2_char       );
  const char* uart_delay_analog_pin3_char        = json["uart_delay_analog_pin3"       ];    if (memcmp (&uart_delay_analog_pin3_char       , &null_str,6)==0) SPIFFS.remove("/config.json"); saveConfig();   sprintf_P(uart_delay_analog_pin3,        ("%s"), uart_delay_analog_pin3_char       );
  const char* uart_delay_analog_pin4_char        = json["uart_delay_analog_pin4"       ];    if (memcmp (&uart_delay_analog_pin4_char       , &null_str,6)==0) SPIFFS.remove("/config.json"); saveConfig();   sprintf_P(uart_delay_analog_pin4,        ("%s"), uart_delay_analog_pin4_char       );
  const char* uart_delay_analog_pin5_char        = json["uart_delay_analog_pin5"       ];    if (memcmp (&uart_delay_analog_pin5_char       , &null_str,6)==0) SPIFFS.remove("/config.json"); saveConfig();   sprintf_P(uart_delay_analog_pin5,        ("%s"), uart_delay_analog_pin5_char       );
  const char* green_light_on_char                = json["green_light_on"               ];    if (memcmp (&green_light_on_char               , &null_str,6)==0) SPIFFS.remove("/config.json"); saveConfig();   sprintf_P(green_light_on,                ("%s"), green_light_on_char               );
  const char* green_light_off_char               = json["green_light_off"              ];    if (memcmp (&green_light_off_char              , &null_str,6)==0) SPIFFS.remove("/config.json"); saveConfig();   sprintf_P(green_light_off,               ("%s"), green_light_off_char              );
  const char* green_light_pin_char               = json["green_light_pin"              ];    if (memcmp (&green_light_pin_char              , &null_str,6)==0) SPIFFS.remove("/config.json"); saveConfig();   sprintf_P(green_light_pin,               ("%s"), green_light_pin_char              );
  const char* green_humidity_threshold_up_char   = json["green_humidity_threshold_up"  ];    if (memcmp (&green_humidity_threshold_up_char  , &null_str,6)==0) SPIFFS.remove("/config.json"); saveConfig();   sprintf_P(green_humidity_threshold_up,   ("%s"), green_humidity_threshold_up_char  );
  const char* green_humidity_threshold_down_char = json["green_humidity_threshold_down"];    if (memcmp (&green_humidity_threshold_down_char, &null_str,6)==0) SPIFFS.remove("/config.json"); saveConfig();   sprintf_P(green_humidity_threshold_down, ("%s"), green_humidity_threshold_down_char);
  const char* green_humidity_sensor_pin_char     = json["green_humidity_sensor_pin"    ];    if (memcmp (&green_humidity_sensor_pin_char    , &null_str,6)==0) SPIFFS.remove("/config.json"); saveConfig();   sprintf_P(green_humidity_sensor_pin,     ("%s"), green_humidity_sensor_pin_char    );
  const char* green_pump_pin_char                = json["green_pump_pin"               ];    if (memcmp (&green_pump_pin_char               , &null_str,6)==0) SPIFFS.remove("/config.json"); saveConfig();   sprintf_P(green_pump_pin,                ("%s"), green_pump_pin_char               );

  configFile.close();
  return true;
}


bool JsonConf::printConfig() {

  Serial.print(F("module_id                    : "));   Serial.println(module_id                    );
  Serial.print(F("sta_ssid                     : "));   Serial.println(sta_ssid                     );
  Serial.print(F("sta_pwd                      : "));   Serial.println(sta_pwd                      );
  Serial.print(F("static_ip_mode               : "));   Serial.println(static_ip_mode               );
  Serial.print(F("static_ip                    : "));   Serial.println(static_ip                    );
  Serial.print(F("static_gateway               : "));   Serial.println(static_gateway               );
  Serial.print(F("static_subnet                : "));   Serial.println(static_subnet                );
  Serial.print(F("ntp_server                   : "));   Serial.println(ntp_server                   );
  Serial.print(F("my_time_zone                 : "));   Serial.println(my_time_zone                 );
  Serial.print(F("mqtt_server                  : "));   Serial.println(mqtt_server                  );
  Serial.print(F("mqtt_port                    : "));   Serial.println(mqtt_port                    );
  Serial.print(F("mqtt_user                    : "));   Serial.println(mqtt_user                    );
  Serial.print(F("mqtt_pwd                     : "));   Serial.println(mqtt_pwd                     );
  Serial.print(F("mqtt_name                    : "));   Serial.println(mqtt_name                    );
  Serial.print(F("publish_topic                : "));   Serial.println(publish_topic                );
  Serial.print(F("subscribe_topic              : "));   Serial.println(subscribe_topic              );
  Serial.print(F("command_pub_topic            : "));   Serial.println(command_pub_topic            );
  Serial.print(F("light_pin                    : "));   Serial.println(light_pin                    );
  Serial.print(F("lightoff_delay               : "));   Serial.println(lightoff_delay               );
  Serial.print(F("light_pin2                   : "));   Serial.println(light_pin2                   );
  Serial.print(F("light2off_delay              : "));   Serial.println(light2off_delay              );
  Serial.print(F("motion_pin                   : "));   Serial.println(motion_pin                   );
  Serial.print(F("dht_pin                      : "));   Serial.println(dht_pin                      );
  Serial.print(F("get_data_delay               : "));   Serial.println(get_data_delay               );
  Serial.print(F("publish_delay                : "));   Serial.println(publish_delay                );
  Serial.print(F("subscribe_delay              : "));   Serial.println(subscribe_delay              );
  Serial.print(F("motion_read_delay            : "));   Serial.println(motion_read_delay            );
  Serial.print(F("reboot_delay                 : "));   Serial.println(reboot_delay                 );
  Serial.print(F("uart_delay_analog_pin0       : "));   Serial.println(uart_delay_analog_pin0       );
  Serial.print(F("uart_delay_analog_pin1       : "));   Serial.println(uart_delay_analog_pin1       );
  Serial.print(F("uart_delay_analog_pin2       : "));   Serial.println(uart_delay_analog_pin2       );
  Serial.print(F("uart_delay_analog_pin3       : "));   Serial.println(uart_delay_analog_pin3       );
  Serial.print(F("uart_delay_analog_pin4       : "));   Serial.println(uart_delay_analog_pin4       );
  Serial.print(F("uart_delay_analog_pin5       : "));   Serial.println(uart_delay_analog_pin5       );
  Serial.print(F("green_light_on               : "));   Serial.println(green_light_on               );
  Serial.print(F("green_light_off              : "));   Serial.println(green_light_off              );
  Serial.print(F("green_light_pin              : "));   Serial.println(green_light_pin              );
  Serial.print(F("green_humidity_threshold_up  : "));   Serial.println(green_humidity_threshold_up  );
  Serial.print(F("green_humidity_threshold_down: "));   Serial.println(green_humidity_threshold_down);
  Serial.print(F("green_humidity_sensor_pin    : "));   Serial.println(green_humidity_sensor_pin    );
  Serial.print(F("green_pump_pin               : "));   Serial.println(green_pump_pin               );
}