FROM node:14
WORKDIR /opt/app

COPY ./package.json ./

COPY ./index.js ./logger.js ./

RUN npm install

RUN mkdir -p -m 777 /var/log/app

RUN useradd -u 2469 banana
USER banana


ENTRYPOINT ["npm", "start"]
