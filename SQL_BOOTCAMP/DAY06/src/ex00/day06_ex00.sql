CREATE TABLE person_discounts(
	id BIGINT NOT NULL PRIMARY KEY,
	person_id BIGINT NOT NULL,
	pizzeria_id BIGINT NOT NULL,
	discount NUMERIC(5, 2) NOT NULL CHECK(discount >= 0 AND discount <= 100) DEFAULT 0,

	CONSTRAINT fk_person_discounts_person_id FOREIGN KEY (person_id) REFERENCES person(id) ON DELETE CASCADE,
	CONSTRAINT fk_person_discounts_pizzeria_id FOREIGN KEY (pizzeria_id) REFERENCES pizzeria(id) ON DELETE CASCADE
);