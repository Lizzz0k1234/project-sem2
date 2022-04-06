FROM ubuntu						
COPY . /usr/src/myapp
WORKDIR /usr/src/myapp

RUN apt update && \
    apt upgrade && \
    apt-get -y install qt5-default

RUN qmake server.pro
RUN make

ENTRYPOINT ["./server"]

