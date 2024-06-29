# Мануал по работе с GitLab

## 1. Создание личного репозитория с нужным .gitignore и простым README.MD

1. Перейдите на главную страницу GitLab
2. Нажмите на кнопку **New project**
3. Выберите **Create blank project**
4. Введите имя проекта и добавьте необходимые данные, добавьте .gitignore
5. Нажмите кнопку **Create project** 

## 2. Создание веток develop и master

1. Перейдите в нужный репозиторий
2. Нажмите на **Repository**, затем **Branches**
3. Нажмите на кнопку **New branch**
4. Введите имя новой ветки develop и нажмите **Create branch**
5. Те же действия повторить для создания ветки master

![day2_img1](misc/rus/images/day2_img1.png)


## 3. установка ветки develop по умолчанию

1. Перейдите в нужный репозиторий
2. Нажмите на **Settings**, затем **Repository**
3. Напротив первого пункта **Branch defaults** нажать **Expand**
4. В качестве Default branch выбрать нужную ветку develop
5. Нажмите на кнопку **Save changes**

![day2_img2](misc/rus/images/day2_img2.png)

## 4. создание issue на создание текущего мануала

1. Перейдите в нужный репозиторий
2. Нажмите на **Issues**
3. Нажмите на кнопку **New issue**
4. Укажите название и описание задачи 
5. Нажмите на кнопку **Create issue**

![day2_img3](misc/rus/images/day2_img3.png)

## 5. создание ветки по issue

1. Перейдите в созданный issue
2. Нажмите на кнопку **Create merge request**
3. В появившемся окне выберите **Create branch**

## 6. создание merge request по ветке в develop

1. Перейдите в нужный репозиторий
2. Нажмите на **Merge requests**
3. Нажмите на кнопку **New merge request**
4. Выберите ветку develop в качестве Source branch и ветку master в качестве Target branch
5. Нажмите на кнопку **Compare branches and continue**
6. Укажите детали и нажмите **Create merge request**

![day2_img4](misc/rus/images/day2_img4.png)

## 7. комментирование и принятие реквеста

1. Перейдите в merge request
2. Добавьте комментарий в **Discussion**
3. Нажмите **Merge**, чтобы принять реквест

## 8. Формирование стабильной версии в master с простановкой тега

1. Перейдите в нужный репозиторий
2. Нажмите на **Repository**, затем **Tags**
3. Нажмите на кнопку **New tag**
4. Укажите имя тега и выберите ветку master
5. Нажмите на кнопку **Create tag**

![day2_img5](misc/rus/images/day2_img5.png)

## 9. Работа с wiki проекта

1. Перейдите в нужный репозиторий
2. Нажмите на **Wiki**
3. В правом верхнем углу страницы нажмите на кнопку **Create your first page**
4. Используйте текстовый редактор для добавления содержимого страницы
5. Нажмите на кнопку **Save page**

![day2_img6](misc/rus/images/day2_img6.png)
