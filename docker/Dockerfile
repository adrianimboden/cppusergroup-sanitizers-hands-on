FROM ubuntu:17.10

RUN \
apt-get update && \
apt-get -y install curl xz-utils libc6-dev libgcc-6-dev && \
curl https://scm.svc.firenet.ch/thingdust/external/binaries/rawfile/6fd465f2527ecd7c03ceb4e46450861dbbedcd6a/clang60.tar.xz -o /root/clang.tar.xz && \
tar -xvf /root/clang.tar.xz -C / && \
apt-get -y purge curl xz-utils && \
rm -rf /var/lib/apt/lists/* && \
rm /root/clang.tar.xz

ENV CC clang
ENV CXX clang++

COPY red_amber_green.rb /usr/local/bin
CMD ["bash", "-c", "trap : TERM INT; sleep infinity & wait"]
