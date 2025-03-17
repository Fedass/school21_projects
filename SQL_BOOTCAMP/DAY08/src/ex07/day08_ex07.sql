-- Session 1
BEGIN;

UPDATE pizzeria SET rating = 4.5 WHERE id = 2;

UPDATE pizzeria SET rating = 3.1 WHERE id = 5;

COMMIT;

-- Session 2
BEGIN;

UPDATE pizzeria SET rating = 3.1 WHERE id = 5;

UPDATE pizzeria SET rating = 4.5 WHERE id = 2;
/* ОШИБКА:  обнаружена взаимоблокировка
DETAIL:  Процесс 23688 ожидает в режиме ShareLock блокировку "транзакция 834"; заблокирован процессом 21316.
Процесс 21316 ожидает в режиме ShareLock блокировку "транзакция 835"; заблокирован процессом 23688.
HINT:  Подробности запроса смотрите в протоколе сервера.
CONTEXT:  при изменении кортежа (0,2) в отношении "pizzeria" */
COMMIT;
-- ROLLBACK