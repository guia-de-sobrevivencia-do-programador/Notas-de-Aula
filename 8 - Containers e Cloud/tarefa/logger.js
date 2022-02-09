const { createLogger, format, transports } = require('winston');

console.log(`${process.env.LOG_PATH || '.'}/nosso-log.log`)
const logger = createLogger({
  level: 'info',
  format: format.combine(
    format.timestamp({
      format: 'YYYY-MM-DD HH:mm:ss'
    }),
    format.errors({ stack: true }),
    format.splat(),
    format.json()
  ),
  defaultMeta: { service: 'gsp-containers', id: Math.random().toString(36) },
  transports: [
    new transports.File({ filename: `${process.env.LOG_PATH || '.'}/nosso-log.log` }),
    new transports.Console(),
  ]
});

module.exports = logger