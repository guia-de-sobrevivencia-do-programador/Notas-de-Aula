const { createLogger, format, transports } = require('winston');

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
  defaultMeta: { service: 'gsp-containers' },
  transports: [
    new transports.File({ filename: '/var/log/app/nosso-log.log' }),
    new transports.Console(),
  ]
});

module.exports = logger