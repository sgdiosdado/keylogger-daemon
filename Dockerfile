FROM gcc:4.9
RUN apt-get -y update && apt-get install -y rsyslog
RUN echo "deb http://us.archive.ubuntu.com/ubuntu/ precise main universe" >> /etc/apt/source.list
RUN mkdir keylogger-daemon
WORKDIR /keylogger-daemon
COPY . .
