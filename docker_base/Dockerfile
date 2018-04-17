FROM ubuntu:17.10

RUN \
apt-get update && \
apt-get -y install curl xz-utils libc6-dev libgcc-6-dev && \
curl https://scm.svc.firenet.ch/thingdust/external/binaries/rawfile/475ebe7226b63ec604484626a5630d26fb7e9a0c/clang60.tar.xz -o /root/clang.tar.xz && \
tar -xvf /root/clang.tar.xz -C / && \
apt-get -y purge curl xz-utils && \
rm -rf /var/lib/apt/lists/* && \
rm /root/clang.tar.xz

ENV CC clang
ENV CXX clang++

CMD ["bash", "-c", "trap : TERM INT; sleep infinity & wait"]
