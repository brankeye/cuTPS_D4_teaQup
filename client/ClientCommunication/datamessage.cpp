#include "datamessage.h"

DataMessage::DataMessage(void) :
    Message(), data(0)
{}

DataMessage::DataMessage(DEST_TYPE dt, ACTION_TYPE at, User* u, QVector<SerializableQObject *>* data_) :
    Message(dt, at, u), data(data_)
{}

DataMessage::~DataMessage(void) {
    if( data != 0 ) {
        QVectorIterator<SerializableQObject*> i(*data);
        while (i.hasNext()) {
            delete (i.next());
        }
        delete data;
        data = 0;
    }
}

void DataMessage::insertToDataStream(QDataStream& ds) const {
    Message::insertToDataStream(ds, DATAMESSAGE);

    ds << static_cast<quint32>(data->size());
    QVectorIterator<SerializableQObject*> i(*data);
    while (i.hasNext()) {
        i.next()->insertToDataStream(ds);
    }
}

bool DataMessage::setFirstData(QVector<SerializableQObject*>* data_) {
    if( data == 0 ) {
        data = data_;
        return true;
    }
    return false;
}

QVector<SerializableQObject*>* DataMessage::extractData(void) {
    QVector<SerializableQObject*>* temp = data;
    data = 0;
    return temp;
}
