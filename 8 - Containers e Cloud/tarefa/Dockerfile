FROM node:14
WORKDIR /opt/app
RUN useradd -u 2469 banana

COPY ./package.json ./

COPY ./index.js ./logger.js ./

RUN npm install

RUN mkdir -p -m 777 /var/log/app

ENV LOG_PATH=/var/log/app

USER banana


ENTRYPOINT ["npm", "start"]
