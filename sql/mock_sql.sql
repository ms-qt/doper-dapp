-- 测试数据的SQL

DELETE
FROM _message_list
WHERE 1 = 1;

INSERT INTO _message_list (_room_id, _room_type, _message_id, _message_type, _event_id, _time)
VALUES ('room001', '_p2p', 'message001', '_text', 'event001', 1580895330);

INSERT INTO _message_list (_room_id, _room_type, _message_id, _message_type, _event_id, _time)
VALUES ('room002', '_p2p', 'message002', '_text', 'event002', 1580895331);

INSERT INTO _message_list (_room_id, _room_type, _message_id, _message_type, _event_id, _time)
VALUES ('room003', '_p2p', 'message003', '_text', 'event003', 1580895332);

INSERT INTO _message_list (_room_id, _room_type, _message_id, _message_type, _event_id, _time)
VALUES ('room004', '_p2p', 'message004', '_text', 'event004', 1580895333);

INSERT INTO _message_list (_room_id, _room_type, _message_id, _message_type, _event_id, _time)
VALUES ('room005', '_p2p', 'message005', '_text', 'event005', 1580895334);


DELETE
FROM _task_list
WHERE 1 = 1;

INSERT INTO _task_list (_user_id, _task_id)
VALUES ('maohuawei', 'task001');
INSERT INTO _task_list (_user_id, _task_id)
VALUES ('maohuawei', 'task002');
INSERT INTO _task_list (_user_id, _task_id)
VALUES ('maohuawei', 'task003');
INSERT INTO _task_list (_user_id, _task_id)
VALUES ('maohuawei', 'task004');
INSERT INTO _task_list (_user_id, _task_id)
VALUES ('maohuawei', 'task005');

DELETE
FROM _task
WHERE 1 = 1;

INSERT INTO _task (_task_id, _task_name, _task_desc, _task_creator_id, _task_executor_id, _task_create_time,
                   _task_start_time, _task_end_time, _task_remark, _task_supervisor, _task_priority)
VALUES ('task001', '登录面板', '使用户能够扫描二维码登录系统', 'maohuawei', 'maohuawei', 1580898126, 1580898126, 1580898126, '难度一般',
        'maohuawei', '高');

INSERT INTO _task (_task_id, _task_name, _task_desc, _task_creator_id, _task_executor_id, _task_create_time,
                   _task_start_time, _task_end_time, _task_remark, _task_supervisor, _task_priority)
VALUES ('task002', '用户名密码登录', '使用户能够使用用户名和密码登录系统', 'maohuawei', 'maohuawei', 1580898126, 1580898126, 1580898126, '难度一般',
        'maohuawei', '高');

INSERT INTO _task (_task_id, _task_name, _task_desc, _task_creator_id, _task_executor_id, _task_create_time,
                   _task_start_time, _task_end_time, _task_remark, _task_supervisor, _task_priority)
VALUES ('task003', '二维码登录', '使用户能够扫描二维码登录系统', 'maohuawei', 'maohuawei', 1580898126, 1580898126, 1580898126, '难度一般',
        'maohuawei', '高');

INSERT INTO _task (_task_id, _task_name, _task_desc, _task_creator_id, _task_executor_id, _task_create_time,
                   _task_start_time, _task_end_time, _task_remark, _task_supervisor, _task_priority)
VALUES ('task004', '通知面板', '使用户能够扫描二维码登录系统', 'maohuawei', 'maohuawei', 1580898126, 1580898126, 1580898126, '难度一般',
        'maohuawei', '高');


INSERT INTO _task (_task_id, _task_name, _task_desc, _task_creator_id, _task_executor_id, _task_create_time,
                   _task_start_time, _task_end_time, _task_remark, _task_supervisor, _task_priority)
VALUES ('task005', '组织架构', '使用户能够扫描二维码登录系统', 'maohuawei', 'maohuawei', 1580898126, 1580898126, 1580898126, '难度一般',
        'maohuawei', '高');

INSERT INTO _task (_task_id, _task_name, _task_desc, _task_creator_id, _task_executor_id, _task_create_time,
                   _task_start_time, _task_end_time, _task_remark, _task_supervisor, _task_priority)
VALUES ('task006', '消息列表', '使用户能够扫描二维码登录系统', 'maohuawei', 'maohuawei', 1580898126, 1580898126, 1580898126, '难度一般',
        'maohuawei', '高');


INSERT INTO _task (_task_id, _task_name, _task_desc, _task_creator_id, _task_executor_id, _task_create_time,
                   _task_start_time, _task_end_time, _task_remark, _task_supervisor, _task_priority)
VALUES ('task007', '任务列表', '使用户能够扫描二维码登录系统', 'maohuawei', 'maohuawei', 1580898126, 1580898126, 1580898126, '难度一般',
        'maohuawei', '高');

DELETE
FROM _room_list
WHERE 1 = 1;

INSERT INTO _room_list (_user_id, _room_id, _room_type)
VALUES ('maohuawei', 'room001', '_p2p');
INSERT INTO _room_list (_user_id, _room_id, _room_type)
VALUES ('maohuawei', 'room002', '_p2p');
INSERT INTO _room_list (_user_id, _room_id, _room_type)
VALUES ('maohuawei', 'room003', '_p2p');
INSERT INTO _room_list (_user_id, _room_id, _room_type)
VALUES ('maohuawei', 'room004', '_p2p');
INSERT INTO _room_list (_user_id, _room_id, _room_type)
VALUES ('maohuawei', 'room005', '_p2p');


DELETE
FROM _room_p2p
WHERE 1 = 1;

INSERT INTO _room_p2p (_room_id, _room_name, _room_avatar, _room_version)
VALUES ('room001', '毛华伟', 'https://b-ssl.duitang.com/uploads/item/201605/14/20160514091932_WCmEc.jpeg', 1);

INSERT INTO _room_p2p (_room_id, _room_name, _room_avatar, _room_version)
VALUES ('room002', '张宁', 'https://b-ssl.duitang.com/uploads/item/201605/14/20160514091932_WCmEc.jpeg', 1);

INSERT INTO _room_p2p (_room_id, _room_name, _room_avatar, _room_version)
VALUES ('room003', '陈春海', 'https://b-ssl.duitang.com/uploads/item/201605/14/20160514091932_WCmEc.jpeg', 1);

INSERT INTO _room_p2p (_room_id, _room_name, _room_avatar, _room_version)
VALUES ('room004', '梁家振', 'https://b-ssl.duitang.com/uploads/item/201605/14/20160514091932_WCmEc.jpeg', 1);

INSERT INTO _room_p2p (_room_id, _room_name, _room_avatar, _room_version)
VALUES ('room005', '隋明君',
        'https://b-ssl.duitang.com/uploads/item/201605/14/20160514091932_WCmEc.jpeg', 1);

INSERT INTO _room_p2p (_room_id, _room_name, _room_avatar, _room_version)
VALUES ('room005', '李卫宁',
        'https://b-ssl.duitang.com/uploads/item/201605/14/20160514091932_WCmEc.jpeg',
        1);

DELETE
FROM _message_text
WHERE 1 = 1;

INSERT INTO _message_text (_room_id, _message_id, _event_id, _sender_id, _time, _text_content, _message_sender_time,
                           _message_receive_time, _is_me, _is_read)
VALUES ('room001', 'message001', 'event001', 'maohuawei', 1580957514429, '在吗', 1580957514429, 1580957514429, true,
        true);

INSERT INTO _message_text (_room_id, _message_id, _event_id, _sender_id, _time, _text_content, _message_sender_time,
                           _message_receive_time, _is_me, _is_read)
VALUES ('room001', 'message002', 'event002', 'maohuawei', 1580957514429, '你好', 1580957514429, 1580957514429, true,
        true);


INSERT INTO _message_text (_room_id, _message_id, _event_id, _sender_id, _time, _text_content, _message_sender_time,
                           _message_receive_time, _is_me, _is_read)
VALUES ('room001', 'message003', 'event003', 'maohuawei', 1580957514429, 'Hello', 1580957514429, 1580957514429, true,
        true);



INSERT INTO _message_text (_room_id, _message_id, _event_id, _sender_id, _time, _text_content, _message_sender_time,
                           _message_receive_time, _is_me, _is_read)
VALUES ('room002', 'message001', 'event001', 'maohuawei', 1580957514429, '在吗', 1580957514429, 1580957514429, true,
        true);


INSERT INTO _message_text (_room_id, _message_id, _event_id, _sender_id, _time, _text_content, _message_sender_time,
                           _message_receive_time, _is_me, _is_read)
VALUES ('room002', 'message002', 'event002', 'maohuawei', 1580957514429, '你好', 1580957514429, 1580957514429, true,
        true);


INSERT INTO _message_text (_room_id, _message_id, _event_id, _sender_id, _time, _text_content, _message_sender_time,
                           _message_receive_time, _is_me, _is_read)
VALUES ('room002', 'message003', 'event003', 'maohuawei', 1580957514429, 'Hello', 1580957514429, 1580957514429, true,
        true);



INSERT INTO _message_text (_room_id, _message_id, _event_id, _sender_id, _time, _text_content, _message_sender_time,
                           _message_receive_time, _is_me, _is_read)
VALUES ('room003', 'message001', 'event001', 'maohuawei', 1580957514429, '在吗', 1580957514429, 1580957514429, true,
        true);


INSERT INTO _message_text (_room_id, _message_id, _event_id, _sender_id, _time, _text_content, _message_sender_time,
                           _message_receive_time, _is_me, _is_read)
VALUES ('room003', 'message002', 'event002', 'maohuawei', 1580957514429, '你好', 1580957514429, 1580957514429, true,
        true);


INSERT INTO _message_text (_room_id, _message_id, _event_id, _sender_id, _time, _text_content, _message_sender_time,
                           _message_receive_time, _is_me, _is_read)
VALUES ('room003', 'message003', 'event003', 'maohuawei', 1580957514429, 'Hello', 1580957514429, 1580957514429, true,
        true);


INSERT INTO _message_text (_room_id, _message_id, _event_id, _sender_id, _time, _text_content, _message_sender_time,
                           _message_receive_time, _is_me, _is_read)
VALUES ('room004', 'message001', 'event001', 'maohuawei', 1580957514429, '在吗', 1580957514429, 1580957514429, true,
        true);


INSERT INTO _message_text (_room_id, _message_id, _event_id, _sender_id, _time, _text_content, _message_sender_time,
                           _message_receive_time, _is_me, _is_read)
VALUES ('room004', 'message002', 'event002', 'maohuawei', 1580957514429, '你好', 1580957514429, 1580957514429, true,
        true);


INSERT INTO _message_text (_room_id, _message_id, _event_id, _sender_id, _time, _text_content, _message_sender_time,
                           _message_receive_time, _is_me, _is_read)
VALUES ('room004', 'message003', 'event003', 'maohuawei', 1580957514429, 'Hello', 1580957514429, 1580957514429, true,
        true);


INSERT INTO _message_text (_room_id, _message_id, _event_id, _sender_id, _time, _text_content, _message_sender_time,
                           _message_receive_time, _is_me, _is_read)
VALUES ('room005', 'message001', 'event001', 'maohuawei', 1580957514429, '在吗', 1580957514429, 1580957514429, true,
        true);


INSERT INTO _message_text (_room_id, _message_id, _event_id, _sender_id, _time, _text_content, _message_sender_time,
                           _message_receive_time, _is_me, _is_read)
VALUES ('room005', 'message002', 'event002', 'maohuawei', 1580957514429, '你好', 1580957514429, 1580957514429, true,
        true);


INSERT INTO _message_text (_room_id, _message_id, _event_id, _sender_id, _time, _text_content, _message_sender_time,
                           _message_receive_time, _is_me, _is_read)
VALUES ('room005', 'message003', 'event003', 'maohuawei', 1580957514429, 'Hello', 1580957514429, 1580957514429, true,
        true);


DELETE
FROM _user
WHERE 1 = 1;


-- 平台管理

INSERT INTO _user (_user_id, _name, _age, _sex, _department, _job_title, _avatar, _signature, _phonenumber, _email, _qq,
                   _introduction, _company)
VALUES ('weiaihui', '魏爱辉', 22, true, '董事长', '平台管理',
        'https://b-ssl.duitang.com/uploads/item/201605/14/20160514091932_WCmEc.jpeg', 'dev', '18935398186',
        'mhw828@sina.com', '898658615', 'dev工程师', '北斗数睿');
INSERT INTO _user (_user_id, _name, _age, _sex, _department, _job_title, _avatar, _signature, _phonenumber, _email, _qq,
                   _introduction, _company)
VALUES ('wangzhiming', '王志明', 22, true, '董事长', '平台管理',
        'https://b-ssl.duitang.com/uploads/item/201605/14/20160514091932_WCmEc.jpeg', 'dev', '18935398186',
        'mhw828@sina.com', '898658615', 'dev工程师', '北斗数睿');
INSERT INTO _user (_user_id, _name, _age, _sex, _department, _job_title, _avatar, _signature, _phonenumber, _email, _qq,
                   _introduction, _company)
VALUES ('wangxiaobo', '王晓波', 22, true, '董事长', '平台管理',
        'https://b-ssl.duitang.com/uploads/item/201605/14/20160514091932_WCmEc.jpeg', 'dev', '18935398186',
        'mhw828@sina.com', '898658615', 'dev工程师', '北斗数睿');
INSERT INTO _user (_user_id, _name, _age, _sex, _department, _job_title, _avatar, _signature, _phonenumber, _email, _qq,
                   _introduction, _company)
VALUES ('lisiqi', '李诗琦', 22, true, '董事长', '平台管理',
        'https://b-ssl.duitang.com/uploads/item/201605/14/20160514091932_WCmEc.jpeg', 'dev', '18935398186',
        'mhw828@sina.com', '898658615', 'dev工程师', '北斗数睿');
INSERT INTO _user (_user_id, _name, _age, _sex, _department, _job_title, _avatar, _signature, _phonenumber, _email, _qq,
                   _introduction, _company)
VALUES ('liyuan', '李媛', 22, true, '董事长', '平台管理',
        'https://b-ssl.duitang.com/uploads/item/201605/14/20160514091932_WCmEc.jpeg', 'dev', '18935398186',
        'mhw828@sina.com', '898658615', 'dev工程师', '北斗数睿');
INSERT INTO _user (_user_id, _name, _age, _sex, _department, _job_title, _avatar, _signature, _phonenumber, _email, _qq,
                   _introduction, _company)
VALUES ('shiyenan', '石亚楠', 22, true, '董事长', '平台管理',
        'https://b-ssl.duitang.com/uploads/item/201605/14/20160514091932_WCmEc.jpeg', 'dev', '18935398186',
        'mhw828@sina.com', '898658615', 'dev工程师', '北斗数睿');

-- 公共关系部

INSERT INTO _user (_user_id, _name, _age, _sex, _department, _job_title, _avatar, _signature, _phonenumber, _email, _qq,
                   _introduction, _company)
VALUES ('weiaihui', '王静静', 22, true, '董事长', '平台管理',
        'https://b-ssl.duitang.com/uploads/item/201605/14/20160514091932_WCmEc.jpeg', 'dev', '18935398186',
        'mhw828@sina.com', '898658615', 'dev工程师', '北斗数睿');
INSERT INTO _user (_user_id, _name, _age, _sex, _department, _job_title, _avatar, _signature, _phonenumber, _email, _qq,
                   _introduction, _company)
VALUES ('liyangxuan', '李洋萱', 22, true, '董事长', '平台管理',
        'https://b-ssl.duitang.com/uploads/item/201605/14/20160514091932_WCmEc.jpeg', 'dev', '18935398186',
        'mhw828@sina.com', '898658615', 'dev工程师', '北斗数睿');
INSERT INTO _user (_user_id, _name, _age, _sex, _department, _job_title, _avatar, _signature, _phonenumber, _email, _qq,
                   _introduction, _company)
VALUES ('wujingyu', '吴婧宇', 22, true, '董事长', '平台管理',
        'https://b-ssl.duitang.com/uploads/item/201605/14/20160514091932_WCmEc.jpeg', 'dev', '18935398186',
        'mhw828@sina.com', '898658615', 'dev工程师', '北斗数睿');


-- 北斗数睿

INSERT INTO _user (_user_id, _name, _age, _sex, _department, _job_title, _avatar, _signature, _phonenumber, _email, _qq,
                   _introduction, _company)
VALUES ('liweining', '李卫宁', 22, true, '董事长', '平台管理',
        'https://b-ssl.duitang.com/uploads/item/201605/14/20160514091932_WCmEc.jpeg', 'dev', '18935398186',
        'mhw828@sina.com', '898658615', 'dev工程师', '北斗数睿');
INSERT INTO _user (_user_id, _name, _age, _sex, _department, _job_title, _avatar, _signature, _phonenumber, _email, _qq,
                   _introduction, _company)
VALUES ('fangshiqi', '方士琦', 22, true, '董事长', '平台管理',
        'https://b-ssl.duitang.com/uploads/item/201605/14/20160514091932_WCmEc.jpeg', 'dev', '18935398186',
        'mhw828@sina.com', '898658615', 'dev工程师', '北斗数睿');
INSERT INTO _user (_user_id, _name, _age, _sex, _department, _job_title, _avatar, _signature, _phonenumber, _email, _qq,
                   _introduction, _company)
VALUES ('wanhaoyan', '汪浩琰', 22, true, '董事长', '平台管理',
        'https://b-ssl.duitang.com/uploads/item/201605/14/20160514091932_WCmEc.jpeg', 'dev', '18935398186',
        'mhw828@sina.com', '898658615', 'dev工程师', '北斗数睿');
INSERT INTO _user (_user_id, _name, _age, _sex, _department, _job_title, _avatar, _signature, _phonenumber, _email, _qq,
                   _introduction, _company)
VALUES ('leijignxing', '雷行京', 22, true, '董事长', '平台管理',
        'https://b-ssl.duitang.com/uploads/item/201605/14/20160514091932_WCmEc.jpeg', 'dev', '18935398186',
        'mhw828@sina.com', '898658615', 'dev工程师', '北斗数睿');
INSERT INTO _user (_user_id, _name, _age, _sex, _department, _job_title, _avatar, _signature, _phonenumber, _email, _qq,
                   _introduction, _company)
VALUES ('luodawei', '罗大伟', 22, true, '董事长', '平台管理',
        'https://b-ssl.duitang.com/uploads/item/201605/14/20160514091932_WCmEc.jpeg', 'dev', '18935398186',
        'mhw828@sina.com', '898658615', 'dev工程师', '北斗数睿');
INSERT INTO _user (_user_id, _name, _age, _sex, _department, _job_title, _avatar, _signature, _phonenumber, _email, _qq,
                   _introduction, _company)
VALUES ('zhangsaifeng', '张赛风', 22, true, '董事长', '平台管理',
        'https://b-ssl.duitang.com/uploads/item/201605/14/20160514091932_WCmEc.jpeg', 'dev', '18935398186',
        'mhw828@sina.com', '898658615', 'dev工程师', '北斗数睿');
INSERT INTO _user (_user_id, _name, _age, _sex, _department, _job_title, _avatar, _signature, _phonenumber, _email, _qq,
                   _introduction, _company)
VALUES ('yangqi', '杨琦', 22, true, '董事长', '平台管理',
        'https://b-ssl.duitang.com/uploads/item/201605/14/20160514091932_WCmEc.jpeg', 'dev', '18935398186',
        'mhw828@sina.com', '898658615', 'dev工程师', '北斗数睿');

-- 产品研发部
INSERT INTO _user (_user_id, _name, _age, _sex, _department, _job_title, _avatar, _signature, _phonenumber, _email, _qq,
                   _introduction, _company)
VALUES ('weiaihui', '孙爱超', 22, true, '董事长', '平台管理',
        'https://b-ssl.duitang.com/uploads/item/201605/14/20160514091932_WCmEc.jpeg', 'dev', '18935398186',
        'mhw828@sina.com', '898658615', 'dev工程师', '北斗数睿');
INSERT INTO _user (_user_id, _name, _age, _sex, _department, _job_title, _avatar, _signature, _phonenumber, _email, _qq,
                   _introduction, _company)
VALUES ('jiangshuai', '蒋帅', 22, true, '董事长', '平台管理',
        'https://b-ssl.duitang.com/uploads/item/201605/14/20160514091932_WCmEc.jpeg', 'dev', '18935398186',
        'mhw828@sina.com', '898658615', 'dev工程师', '北斗数睿');
INSERT INTO _user (_user_id, _name, _age, _sex, _department, _job_title, _avatar, _signature, _phonenumber, _email, _qq,
                   _introduction, _company)
VALUES ('liwei', '李伟', 22, true, '董事长', '平台管理',
        'https://b-ssl.duitang.com/uploads/item/201605/14/20160514091932_WCmEc.jpeg', 'dev', '18935398186',
        'mhw828@sina.com', '898658615', 'dev工程师', '北斗数睿');


-- 市场合作部
INSERT INTO _user (_user_id, _name, _age, _sex, _department, _job_title, _avatar, _signature, _phonenumber, _email, _qq,
                   _introduction, _company)
VALUES ('jianshijie', '姜世杰', 22, true, '董事长', '平台管理',
        'https://b-ssl.duitang.com/uploads/item/201605/14/20160514091932_WCmEc.jpeg', 'dev', '18935398186',
        'mhw828@sina.com', '898658615', 'dev工程师', '北斗数睿');
INSERT INTO _user (_user_id, _name, _age, _sex, _department, _job_title, _avatar, _signature, _phonenumber, _email, _qq,
                   _introduction, _company)
VALUES ('shilei', '石磊', 22, true, '董事长', '平台管理',
        'https://b-ssl.duitang.com/uploads/item/201605/14/20160514091932_WCmEc.jpeg', 'dev', '18935398186',
        'mhw828@sina.com', '898658615', 'dev工程师', '北斗数睿');


-- 研发部

INSERT INTO _user (_user_id, _name, _age, _sex, _department, _job_title, _avatar, _signature, _phonenumber, _email, _qq,
                   _introduction, _company)
VALUES ('chenchunhai', '陈春海', 22, true, '首席架构师', '研发部',
        'https://b-ssl.duitang.com/uploads/item/201605/14/20160514091932_WCmEc.jpeg', 'dev', '18935398186',
        'mhw828@sina.com', '898658615', 'dev工程师', '北斗数睿');
INSERT INTO _user (_user_id, _name, _age, _sex, _department, _job_title, _avatar, _signature, _phonenumber, _email, _qq,
                   _introduction, _company)
VALUES ('liangjiazheng', '梁家振', 22, true, '平台开发', '研发部',
        'https://b-ssl.duitang.com/uploads/item/201605/14/20160514091932_WCmEc.jpeg', 'dev', '18935398186',
        'mhw828@sina.com', '898658615', 'dev工程师', '北斗数睿');
INSERT INTO _user (_user_id, _name, _age, _sex, _department, _job_title, _avatar, _signature, _phonenumber, _email, _qq,
                   _introduction, _company)
VALUES ('suimingjun', '隋明君', 22, true, 'IOS', '研发部',
        'https://b-ssl.duitang.com/uploads/item/201605/14/20160514091932_WCmEc.jpeg', 'dev', '18935398186',
        'mhw828@sina.com', '898658615', 'dev工程师', '北斗数睿');
INSERT INTO _user (_user_id, _name, _age, _sex, _department, _job_title, _avatar, _signature, _phonenumber, _email, _qq,
                   _introduction, _company)
VALUES ('maohuawei', '毛华伟', 22, true, 'Android', '研发部',
        'https://b-ssl.duitang.com/uploads/item/201605/14/20160514091932_WCmEc.jpeg', 'dev', '18935398186',
        'mhw828@sina.com', '898658615', 'dev工程师', '北斗数睿');
INSERT INTO _user (_user_id, _name, _age, _sex, _department, _job_title, _avatar, _signature, _phonenumber, _email, _qq,
                   _introduction, _company)
VALUES ('zhangning', '张宁', 22, true, 'Qt', '研发部',
        'https://b-ssl.duitang.com/uploads/item/201605/14/20160514091932_WCmEc.jpeg', 'dev', '18935398186',
        'mhw828@sina.com', '898658615', 'dev工程师', '北斗数睿');
