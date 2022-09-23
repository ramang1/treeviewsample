#include <QFileSystemModel>
#include <QSet>

class CustomModel : public QFileSystemModel {
    Q_OBJECT
    public:
        explicit CustomModel(QObject *parent = Q_NULLPTR);

        QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;
        bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) Q_DECL_OVERRIDE;

        Qt::ItemFlags flags(const QModelIndex& index) const Q_DECL_OVERRIDE;

    private:
        QMap<QPersistentModelIndex, Qt::CheckState> checklist;

        bool setNodeCheckState(const QModelIndex & index, const QVariant & value, int role);
        bool setChildNodesCheck (const QModelIndex & index, const QVariant & value);

        bool setParentNodeCheckState(const QModelIndex& currentNodeIndex);
        Qt::CheckState getCheckStateAccordingToChildren(const QModelIndex& currentNodeIndex);
};
