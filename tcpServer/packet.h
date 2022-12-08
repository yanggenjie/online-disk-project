#ifndef PACKET_H
#define PACKET_H
#include <QStringList>
#define REGIST_OK "regist ok"
#define REGIST_FAILED "regist failed"
#define LOGIN_OK "login ok"
#define LOGIN_FAILED "login failed"
#define SEARCH_USER_NONE "user not exist"
#define SEARCH_USER_ONLINE "user online"
#define SEARCH_USER_OFFLINE "user offline"
#define ADD_FRI_UNKONW_ERROR "unknow"
#define ADD_FRI_SELF "can't add youself"
#define ADD_FRI_ALREADY "already friend"
#define ADD_FRI_NO_ONLINE "not friend online"
#define ADD_FRI_NO_OFFLINE "not friend offline"
#define ADD_FRI_SUCCESS "add friend success"
#define ADD_FRI_FAILED "add friend failed"
#define DELETE_FRI_SUCCESS "delete success"
#define DELETE_FRI_FAILED "delete failed"
#define DIR_NO_EXIST "dir not exist"
#define FILE_NAME_EXIST "file name exist"
#define DIR_CREATE_OK "create dir ok"
#define DEL_DIR_OK "delete dir ok"
#define DEL_DIR_FAILED "can't del file"
#define DEL_FILE_OK "delete file ok"
#define DEL_FILE_FAILED "can't del Dir"
#define RENAME_FILE_OK "rename ok"
#define RENAME_FILE_FAILED "rename failed"
#define ENTER_DIR_FAILED "enter dir failed"
#define UPLOAD_FILE_OK "upload file ok"
#define UPLOAD_FILE_FAILED "upload file failed"
#define ACCEPT_SHARE_FILE "accept share file"
#define REFUSE_SHARE_FILE "refuse share file"
#define SHARE_FILE_OK "share file ok"
#define MOVE_FILE_OK "move file ok"
#define MOVE_FILE_FAILED "move file failed"
#define COMMON_ERR "server is busy"

enum MSG_TYPE {
    MSG_TYPE_DEFAULT,
    MSG_TYPE_REGIST_REQUEST, // 注册请求
    MSG_TYPE_REGIST_RESPOND, // 注册回复
    MSG_TYPE_LOGIN_REQUEST, // 登录请求
    MSG_TYPE_LOGIN_RESPOND, // 登录回复

    MSG_TYPE_SHOWONLINE_REQUEST, // 显示在线用户请求
    MSG_TYPE_SHOWONLINE_RESPOND, // 显示在线用户回复

    MSG_TYPE_REFRESH_FRI_REQUEST, // 显示我的好友列表请求
    MSG_TYPE_REFRESH_FRI_RESPOND, // 显示我的好友列表回复

    MSG_TYPE_SERACH_REQUEST, // 查询请求
    MSG_TYPE_SERACH_RESPOND, // 查询回复

    MSG_TYPE_ADDFRIEND_REQUEST, // 添加好友请求
    MSG_TYPE_ADDFRIEND_RESPOND, // 添加好友回复

    MSG_TYPE_ADDFRIEND_ACCEPT_REQUEST, // 接受好友请求
    MSG_TYPE_ADDFRIEND_REFUSE_REQUEST, // 拒绝好友请求

    MSG_TYPE_ADDFRIEND_ACCEPT_RESPOND, // 接受好友回复
    MSG_TYPE_ADDFRIEND_REFUSE_RESPOND, // 拒绝好友回复

    MSG_TYPE_DELETE_FRIEND_REQUEST, // 删除好友请求
    MSG_TYPE_DELETE_FRIEND_RESPOND, // 删除好友回复

    MSG_TYPE_PRIVATE_CHAT_REQUEST, // 私聊请求
    MSG_TYPE_PRIVATE_CHAT_RESPOND, // 私聊回复

    MSG_TYPE_GROUP_CHAT_REQUEST, // 群聊请求
    MSG_TYPE_GROUP_CHAT_RESPOND, // 群聊回复

    MSG_TYPE_CREATE_DIR_REQUEST, // 创建文件夹请求
    MSG_TYPE_CREATE_DIR_RESPOND, // 创建文件夹回复

    MSG_TYPE_REFRESH_FILELIST_REQUEST, // 刷新文件列表请求
    MSG_TYPE_REFRESH_FILELIST_RESPOND, // 刷新文件列表回复

    MSG_TYPE_DEL_DIR_REQUEST, // 删除目录请求
    MSG_TYPE_DEL_DIR_RESPOND, // 删除目录回复
    MSG_TYPE_DEL_FILE_REQUEST, // 删除常规文件请求
    MSG_TYPE_DEL_FILE_RESPOND, // 删除常规文件回复

    MSG_TYPE_RENAME_FILE_REQUEST, // 重命名文件请求
    MSG_TYPE_RENAME_FILE_RESPOND, // 重命名文件回复

    MSG_TYPE_ENTER_DIR_REQUEST, // 进入文件夹请求
    MSG_TYPE_ENTER_DIR_RESPOND, // 进入文件夹回复
    MSG_TYPE_UPLOAD_FILE_REQUEST, // 上传文件请求
    MSG_TYPE_UPLOAD_FILE_RESPOND, // 上传文件回复
    MSG_TYPE_DOWNLOAD_FILE_REQUEST, // 下载文件请求
    MSG_TYPE_DOWNLOAD_FILE_RESPOND, // 下载文件回复
    MSG_TYPE_SHARE_FILE_REQUEST, // 共享文件请求
    MSG_TYPE_SHARE_FILE_RESPOND, // 共享文件回复
    MSG_TYPE_SHARE_FILE_NOTICE, // 共享文件通知
    MSG_TYPE_SHARE_FILE_NOTICE_RESPOND, // 共享文件通知回复
    MSG_TYPE_MOVE_FILE_REQUEST, // 移动文件请求
    MSG_TYPE_MOVE_FILE_RESPOND, // 移动文件回复
};

enum QUERY_TYPE {
    QUERY_TYPE_NOT_EXIST,
    QUERY_TYPE_EXIST_ONLINE,
    QUERY_TYPE_EXIST_OFFLINE,
};

enum FRIEND_TYPE {
    FRI_TYPE_UNKNOW_ERROR, // 未知错误
    FRI_TYPE_SELF, // 账号本身
    FRI_TYPE_ALREADY, // 已是好友
    FRI_TYPE_NO_ONLINE, // 不是好友，对方在线
    FRI_TYPE_NO_OFFLINE, // 不是好友，对方不在线
    FRI_TYPE_NOT_EXIST, // 对方账户不存在
};

class packet {
    int m_packetSize; // 包体总大小
    short int m_msgType; // 包头
    char m_localBuffer[4096];
    int m_count;

public:
    packet();
    void setMsgType(MSG_TYPE type);
    MSG_TYPE getMsgType();

    char* data();
    int packetSize();

    void append(const QString& val);
    QStringList getData();
    void clear();
};

#endif // PACKET_H
