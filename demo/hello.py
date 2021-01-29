import logging, time
import logging.handlers

log = logging.getLogger('MyLogger')
log.setLevel(logging.DEBUG)
handler = logging.handlers.SysLogHandler(address = '/dev/log')
log.addHandler(handler)

while True:
    log.debug('hello, world')
    time.sleep(10)

