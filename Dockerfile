# (1) Build
FROM ubuntu:18.04 as builder

RUN apt update
RUN apt install -y --allow-unauthenticated \
    gcc \
    make \
    cmake \
    flex \
    bison \
    libjson-c-dev
