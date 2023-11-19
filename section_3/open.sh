#!/bin/bash

file_mime_type=$(file -b --mime-type "$1")


case $file_mime_type in
    "image/png" | "image/jpeg" | "image/jpg"  | "image/gif")
        gimp "$1" ;;
    "application/pdf" | "application/vnd.openxmlformats-officedocument.wordprocessingml.document"  | "text/plain")
        libreoffice --writer "$1" ;;
    "video/mp4" | "video/ogg" | "audio/mpeg")
        mpv "$1" ;;
    *)
        echo "Невозможно открыть файл $1, неизвестный MIME-тип: $file_mime_type" ;;
esac
