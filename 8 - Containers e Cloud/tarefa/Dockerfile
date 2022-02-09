FROM node:14
WORKDIR /opt/app

COPY ./package.json ./

COPY ./index.js ./

RUN npm install

RUN useradd -u 2469 banana
USER banana


ENTRYPOINT ["npm", "start"]
