-- APP sql

--- 用户凭证


drop table IF EXISTS _certificate;

CREATE TABLE IF NOT EXISTS _certificate
(
    _id            integer primary key autoincrement,
    _user_id       varchar(256),
    _username      varchar(256),
    _password      varchar(256),
    _access_token  varchar(256),
    _refresh_token varchar(256),
    _login_type    varchar(256),
    _save_password boolean,
    _auto_login    boolean,
    _time          bigint
);

drop table IF EXISTS _user;
--- user

CREATE TABLE IF NOT EXISTS _user
(
    _id           integer primary key autoincrement,
    _user_id      varchar(256),
    _name         varchar(256),
    _age          integer,
    _sex          integer,
    _department   varchar(256),
    _job_title    varchar(256),
    _avatar       varchar(1024),
    _signature    varchar(1024),
    _phonenumber  varchar(256),
    _email        varchar(256),
    _qq           varchar(256),
    _introduction text,
    _company      varchar(256)
);

drop table IF EXISTS _buddy;

CREATE TABLE IF NOT EXISTS _buddy
(
    _id       integer primary key autoincrement,
    _user_id  varchar(256),
    _buddy_id varchar(256)
);


drop table IF EXISTS _room_p2p;

CREATE TABLE IF NOT EXISTS _room_p2p
(
    _id           integer primary key autoincrement,
    _room_id      varchar(256),
    _room_name    varchar(256),
    _room_avatar  varchar(1024),
    _room_version integer
);

drop table IF EXISTS _room_group;

CREATE TABLE IF NOT EXISTS _room_group
(
    _id           integer primary key autoincrement,
    _room_id      varchar(256),
    _room_name    varchar(256),
    _room_avatar  varchar(1024),
    _room_version integer
);



drop table IF EXISTS _room_discussion_group;

CREATE TABLE IF NOT EXISTS _room_discussion_group
(
    _id           integer primary key autoincrement,
    _room_id      varchar(256),
    _room_name    varchar(256),
    _room_avatar  varchar(1024),
    _room_version integer
);


drop table IF EXISTS _room_task;

CREATE TABLE IF NOT EXISTS _room_task
(
    _id           integer primary key autoincrement,
    _room_id      varchar(256),
    _room_name    varchar(256),
    _room_avatar  varchar(1024),
    _room_version integer
);

drop table IF EXISTS _room_list;

CREATE TABLE IF NOT EXISTS _room_list
(
    _id        integer primary key autoincrement,
    _user_id   varchar(256),
    _room_id   varchar(256),
    _room_type varchar(256)
);

drop table IF EXISTS _room_menber;

CREATE TABLE IF NOT EXISTS _room_menber
(
    _id      integer primary key autoincrement,
    _room_id varchar(256),
    _user_id varchar(256)
);

drop table IF EXISTS _message_text;

CREATE TABLE IF NOT EXISTS _message_text
(
    _id                   integer primary key autoincrement,
    _room_id              varchar(255),
    _message_id           varchar(255),
    _event_id             varchar(255),
    _sender_id            varchar(255),
    _time                 bigint,
    _text_content         text,
    _message_sender_time  bigint,
    _message_receive_time bigint,
    _is_me                boolean,
    _is_read              boolean,
    _is_send_success      boolean
);

drop table IF EXISTS _message_list;

CREATE TABLE IF NOT EXISTS _message_list
(
    _id           integer primary key autoincrement,
    _room_id      varchar(256),
    _room_type    varchar(256),
    _message_id   varchar(256),
    _message_type varchar(256),
    _event_id     varchar(256),
    _time         bigint
);


drop table IF EXISTS _task;

CREATE TABLE IF NOT EXISTS _task
(
    _id               integer primary key autoincrement,
    _task_id          varchar(256),
    _task_name        varchar(256),
    _task_desc        text,
    _task_creator_id  varchar(256),
    _task_executor_id varchar(256),
    _task_create_time bigint,
    _task_start_time  bigint,
    _task_end_time    bigint,
    _task_remark      text,
    _task_supervisor  varchar(256),
    _task_priority    varchar(256),
    _task_status      varchar(256)
);


drop table IF EXISTS _task_list;

CREATE TABLE IF NOT EXISTS _task_list
(
    _id      integer primary key autoincrement,
    _user_id varchar(256),
    _task_id varchar(256)
);


drop table IF EXISTS _organization_department;

CREATE TABLE IF NOT EXISTS _organization_department
(
    _id                      integer primary key autoincrement,
    _department_id           varchar(255),
    _department_name         varchar(255),
    _department_number_count integer,
    _department_desc         varchar(255)
);

drop table IF EXISTS _organization_member;

CREATE TABLE IF NOT EXISTS _organization_member
(
    _id              integer primary key autoincrement,
    _department_id   varchar(255),
    _department_name varchar(255),
    _user_id         varchar(255)
);