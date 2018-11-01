echo "stream started"
/usr/local/bin/mjpg_streamer -i "/usr/local/lib/input_file.so -f /home/pi/Desktop/Distance_Measurement -n nurhak.jpg" -o "/usr/local/lib/output_http.so -p 8080 -w /usr/local/www"&

