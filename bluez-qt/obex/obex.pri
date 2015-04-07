!exists(obexagent.h):system($$[QT_HOST_BINS]/qdbusxml2cpp -c ObexAgentAdaptor -a obexagent.h:obexagent.cpp agent.xml)
!exists(obexclient.h):system($$[QT_HOST_BINS]/qdbusxml2cpp -c ObexClientInterface -p obexclient.h:obexclient.cpp client.xml)
!exists(obexobjectpush.h):system($$[QT_HOST_BINS]/qdbusxml2cpp -c ObexObjectPushInterface -p obexobjectpush.h:obexobjectpush.cpp -i bluezobextypes.h objectpush.xml)
!exists(obexfiletransfer.h):system($$[QT_HOST_BINS]/qdbusxml2cpp -c ObexFileTransferInterface -p obexfiletransfer.h:obexfiletransfer.cpp -i bluezobextypes.h filetransfer.xml)
!exists(obexsession.h):system($$[QT_HOST_BINS]/qdbusxml2cpp -c ObexSessionInterface -p obexsession.h:obexsession.cpp session.xml)
!exists(obextransfer.h):system($$[QT_HOST_BINS]/qdbusxml2cpp -c ObexTransferInterface -p obextransfer.h:obextransfer.cpp transfer.xml)

SOURCES += obex/obexagent.cpp \
    obex/obexclient.cpp \
    obex/obexobjectpush.cpp \
    obex/obexfiletransfer.cpp \
    obex/obexsession.cpp \
    obex/obextransfer.cpp

HEADERS += obex/obexagent.h \
    obex/obexclient.h \
    obex/obexobjectpush.h \
    obex/obexfiletransfer.h \
    obex/obexsession.h \
    obex/obextransfer.h \
    obex/bluezobextypes.h

