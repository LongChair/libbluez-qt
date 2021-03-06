#ifndef BLUETOOTHDEVICEMODEL_H
#define BLUETOOTHDEVICEMODEL_H

#include <QAbstractListModel>
#include "bluemanager.h"
#include "blueadapter.h"
#include "bluetoothdevice.h"

class BluetoothDevicesModel : public QAbstractListModel
{
	Q_OBJECT
	
	Q_PROPERTY(bool powered READ powered WRITE makePowered NOTIFY poweredChanged)
	Q_PROPERTY(bool discoverable READ discoverable WRITE makeDiscoverable NOTIFY discoverableChanged)
	Q_PROPERTY(int discoverableTimeout READ discoverableTimeout WRITE setDiscoverableTimeout NOTIFY discoverableTimeoutChanged)
	Q_PROPERTY(bool adapterPresent READ adapterPresent NOTIFY adapterChanged)
	Q_PROPERTY(bool connected READ connected NOTIFY connectedChanged)

public:
	explicit BluetoothDevicesModel(QObject *parent = 0);

	bool adapterPresent() { return adapter != NULL; }

public slots:

	int columnCount(const QModelIndex &) const { return 1; }
	int rowCount(const QModelIndex &parent = QModelIndex()) const;
	QVariant data(const QModelIndex &index, int role) const;

	QString devicePath(QString name);

	QList<BluetoothDevice*> devices(){ return m_devices; }

	bool connected() { return m_connected; }

	BluetoothDevice* device(QString path);
	BluetoothDevice* deviceByHwAddress(QString addy);
	void makePowered(bool poweredValue);
	bool powered();
	void makeDiscoverable(bool discoverableValue);
	bool discoverable();
	int discoverableTimeout();
	void setDiscoverableTimeout(int timeout);

#if QT_VERSION >= QT_VERSION_CHECK(5, 0, 0)
protected:
    virtual QHash<int, QByteArray> roleNames() const;
#endif

private slots:
	void defaultAdapterChanged(QDBusObjectPath);
	void adapterRemoved(QDBusObjectPath);
	void deviceCreated(QDBusObjectPath);
	void deviceRemoved(QDBusObjectPath);

	void devicePropertyChanged(QString name, QVariant value);
	void adapterPropertyChanged(QString name, QDBusVariant value);

signals:
	void poweredChanged(bool powered);
	void discoverableTimeoutChanged(int timeout);
	void devicePaired(BluetoothDevice* device);
	void discoverableChanged(bool discoverable);
	void adapterChanged(bool adapterPresent);
	void connectedChanged(bool isConnected);

private:
	void updateConnected(bool deviceconnectedStatus);
	void clearModel();

	bool m_connected;
	OrgBluezManagerInterface *manager;
	OrgBluezAdapterInterface *adapter;
	QList<BluetoothDevice*> m_devices;
    QHash<int, QByteArray> m_roleNames;
};

#endif // BLUETOOTHDEVICEMODEL_H
