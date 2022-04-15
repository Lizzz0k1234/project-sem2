FROM ubuntu						
COPY . /usr/src/myapp
WORKDIR /usr/src/myapp

RUN apt update && \
    DEBIAN_FRONTEND=noninteractive apt-get -y install qt5-default && \
    apt -y install build-essential

RUN qmake echoServer.pro
RUN make

ENTRYPOINT ["./echoServer"]

