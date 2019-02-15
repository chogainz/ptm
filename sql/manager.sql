USE db658819889;

 -- --------------------------------------------------------

CREATE TABLE project(project_id INT, project_title VARCHAR(100) NOT NULL, project_description VARCHAR(255) NOT NULL, project_created VARCHAR(100) NOT NULL, project_modified TIMESTAMP NOT NULL, project_completed CHAR(1) NOT NULL, user_id INT(11) NOT NULL, PRIMARY KEY (project_id));


CREATE TABLE task(task_id int(8), task_title VARCHAR(22) NOT NULL, task_description varchar(255) NOT NULL, task_created TIMESTAMP NOT NULL, task_modified TIMESTAMP NOT NULL, task_completed CHAR(1) NOT NULL, project_id INT(8) DEFAULT NULL, PRIMARY KEY(task_id), UNIQUE KEY task_id(task_id), KEY project_id(project_id), KEY task_id_2(task_id));


CREATE TABLE user(user_id int(11) NOT NULL AUTO_INCREMENT, username varchar(22) NOT NULL, password varchar(40) NOT NULL, first_name varchar(22) NOT NULL, last_name varchar(22) NOT NULL, dob varchar(22) NOT NULL, address varchar(255) NOT NULL, postcode varchar(10) NOT NULL, email varchar(50) NOT NULL, PRIMARY KEY (user_id));


INSERT INTO USER (user_id,
                  username,
                  password,
                  first_name,
                  last_name,
                  dob,
                  address,
                  postcode,
                  email)
VALUES(1,
       'username',
       '5baa61e4c9b93f3f0682250b6cf8331b7ee68fd8',
       'joe',
       'Wadsworth',
       '24/01/1985',
       '31 Reva Road',
       'ST16 3BT',
       'fitnetjoe@live.co.uk');

