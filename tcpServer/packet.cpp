#include "packet.h"

packet::packet()
{
    memset(m_localBuffer, 0, 4096);
    m_count = 0;
    m_packetSize = 6;
}

void packet::setMsgType(MSG_TYPE type)
{
    this->m_msgType = type;
}

MSG_TYPE packet::getMsgType()
{
    return (MSG_TYPE)m_msgType;
}

char* packet::data()
{
    return (char*)this;
}

int packet::packetSize()
{
    return m_packetSize;
}

// 打包数据
void packet::append(const QString& val)
{
    short size = strlen(val.toLocal8Bit().data());
    memcpy(m_localBuffer + m_count, &size, 2); // 前两个字节记录数据大小
    m_count += 2;

    memcpy(m_localBuffer + m_count, val.toLocal8Bit().data(), size); // 后面记录数据内容
    m_count += size; // 记录指针位置，标记下一个数据起始位置

    m_packetSize = 4 + 2 + m_count; // 更新包体总大小 4个字节为包体总大小，2个字节为包头，m_count为实际内容大小
}

// 解析数据
QStringList packet::getData()
{
    int rd_count = 0;
    short size = 0;
    QStringList list;
    while (1) {
        memcpy(&size, m_localBuffer + rd_count, 2); // 读取数据大小
        rd_count += 2;

        char temp[size + 1] = { 0 }; // 根据读取的数据大小构建临时缓存区域
        memcpy(temp, m_localBuffer + rd_count, size); // 复制数据到临时缓存区域

        // 添加数据到list
        QString data = QString::fromLocal8Bit(temp);
        list.append(data);
        // 读取下一个数据
        rd_count += size;
        if (m_localBuffer[rd_count] == 0) {
            break;
        }
    }
    // 读取完数据之后，清空buf
    clear();
    return list;
}

void packet::clear()
{
    memset(m_localBuffer, 0, 4096);
    m_count = 0;
    m_packetSize = 6;
}
