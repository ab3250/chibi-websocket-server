#!/usr/bin/env bash

sudo killall nginx > /dev/null 2>&1

sudo killall chibi-scheme > /dev/null 2>&1

#set nginx web root directory

sed -i '/.*set \$rtdir.*/c\set $rtdir '"$(pwd)"';' $(pwd)/../nginx/conf/nginx.conf

sudo $(pwd)/../nginx/sbin/nginx -c $(pwd)/../nginx/conf/nginx.conf

#socket
chibi-scheme -r main.scm &

google-chrome-stable http://localhost:8000/www/index.html




