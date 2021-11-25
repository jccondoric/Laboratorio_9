#include "Bomberman.h"

Bomberman::Bomberman(std::shared_ptr<SDL_Texture> _texture, SDL_Renderer* _renderer):GamePawn(_texture, _renderer) {
	
	/*tileActual = _tileActual;
	tileSiguiente = nullptr;*/

	/*if (tileActual != nullptr) {
		tileActual->setBomberman(this);

		posicionX = tileActual->getPosicionTileX() * Tile::anchoTile;
		posicionY = tileActual->getPosicionTileY() * Tile::altoTile;
		ancho = Tile::anchoTile;
		alto = Tile::altoTile;

		setPosition(tileActual->getPosicionTileX() * Tile::anchoTile, tileActual->getPosicionTileY() * Tile::altoTile);
		setSize(Tile::anchoTile, Tile::altoTile);
	}
	else {
		posicionX = 0;
		posicionY = 0;
		ancho = Tile::anchoTile;
		alto = Tile::altoTile;
	}*/

	/*velocidad = 1;
	movil = true;
	enMovimiento = false;
	direccionActual = MOVE_DIRECTION_NONE;
	direccionSiguiente = MOVE_DIRECTION_NONE;*/

	animations = std::make_shared<Animation>();
	animations->addAnimationEntity(AnimationEntity(0, 0, ancho, alto));
	animations->addAnimationEntity(AnimationEntity(ancho * 1, 0, ancho, alto));
	animations->addAnimationEntity(AnimationEntity(ancho * 2, 0, ancho, alto));
	//animacion->addAnimationEntity(AnimationEntity(ancho * 3, 0, ancho, alto));
	/*animacion->addAnimationEntity(AnimationEntity(ancho * 4, 0, ancho, alto));
	animacion->addAnimationEntity(AnimationEntity(ancho * 5, 0, ancho, alto));
	animacion->addAnimationEntity(AnimationEntity(ancho * 6, 0, ancho, alto));
	animacion->addAnimationEntity(AnimationEntity(ancho * 7, 0, ancho, alto));*/
	animations->setSprite(this);
	addAnimation(animations);

	animacion->play();


};

void Bomberman::update()
{
	direccionSiguiente = MOVE_DIRECTION_NONE;

	if (keyboardInput->IsKeyOn(botonAbajo)) {
		direccionSiguiente = MOVE_DIRECTION_ABAJO;
	}
	else if (keyboardInput->IsKeyOn(botonArriba)) {
		direccionSiguiente = MOVE_DIRECTION_ARRIBA;
	}
	else if (keyboardInput->IsKeyOn(botonDerecha)) {
		direccionSiguiente = MOVE_DIRECTION_DERECHA;
	}
	else if (keyboardInput->IsKeyOn(botonIzquierda)) {
		direccionSiguiente = MOVE_DIRECTION_IZQUIERDA;
	}
		

	//if (tileActual != nullptr && tileActual->getSueloCesped() != nullptr) {
	//	//Camina normalmente, se revisan colisiones
	//}

	// Animar Bomberman
	//if (enMovimiento) {
	//	//GameActor::update();
	//}

	//// Cambiar de direccion y tileSiguiente
	//if (tileActual != nullptr && tileActual->getSueloCesped() != nullptr) {
	//	//Camina normalmente, se revisan colisiones
	//}

	//if (tileSiguiente == tileActual || tileSiguiente == nullptr) {
		if (direccionSiguiente != direccionActual && tratarDeMover(direccionSiguiente))
			direccionActual = direccionSiguiente;
		else
			tratarDeMover(direccionActual);

		/*if (tileSiguiente == nullptr)
			enMovimiento = false;
		else
			enMovimiento = true;*/
	//}
	//else {
	if (tileSiguiente != nullptr) {
		switch (direccionActual) {
		case MOVE_DIRECTION_ARRIBA:
			posicionY = std::max(posicionY - velocidad, tileSiguiente->getPosicionTileY() * Tile::altoTile);
			//posicionY = posicionY - velocidad;
			break;
		case MOVE_DIRECTION_ABAJO:
			posicionY = std::min(posicionY + velocidad, tileSiguiente->getPosicionTileY() * Tile::altoTile);
			//posicionY = posicionY + velocidad;
			break;
		case MOVE_DIRECTION_IZQUIERDA:
			posicionX = std::max(posicionX - velocidad, tileSiguiente->getPosicionTileX() * Tile::anchoTile);
			//posicionX = posicionX - velocidad;
			break;
		case MOVE_DIRECTION_DERECHA:
			posicionX = std::min(posicionX + velocidad, tileSiguiente->getPosicionTileX() * Tile::anchoTile);
			//posicionX = posicionX + velocidad;
			break;
		}

		// Asignacion de coliciones
		//
		//

		// Cambio de direccion

		if ((direccionActual == MOVE_DIRECTION_ABAJO || direccionActual == MOVE_DIRECTION_ARRIBA) && posicionY == tileSiguiente->getPosicionTileY() * Tile::altoTile)
			setTileActual(tileSiguiente);

		if ((direccionActual == MOVE_DIRECTION_IZQUIERDA || direccionActual == MOVE_DIRECTION_DERECHA) && posicionX == tileSiguiente->getPosicionTileX() * Tile::anchoTile)
			setTileActual(tileSiguiente);
	}
	//}
}

void Bomberman::render()
{
	GamePawn::render();
}

void Bomberman::render(SDL_Rect& _camara) {
	GamePawn::render(_camara);
}

void Bomberman::update(const unsigned int delta) {
	direccionSiguiente = MOVE_DIRECTION_NONE;

	if (keyboardInput->IsKeyOn(botonAbajo)) {
		direccionSiguiente = MOVE_DIRECTION_ABAJO;
	}
	else if (keyboardInput->IsKeyOn(botonArriba)) {
		direccionSiguiente = MOVE_DIRECTION_ARRIBA;
	}
	else if (keyboardInput->IsKeyOn(botonDerecha)) {
		direccionSiguiente = MOVE_DIRECTION_DERECHA;
	}
	else if (keyboardInput->IsKeyOn(botonIzquierda)) {
		direccionSiguiente = MOVE_DIRECTION_IZQUIERDA;
	}

	if (direccionSiguiente != direccionActual && tratarDeMover(direccionSiguiente))
		direccionActual = direccionSiguiente;
	else
		tratarDeMover(direccionActual);

	/*if (tileSiguiente == nullptr)
		enMovimiento = false;
	else
		enMovimiento = true;*/
		//}
		//else {
	if (tileSiguiente != nullptr) {
		switch (direccionActual) {
		case MOVE_DIRECTION_ARRIBA:
			posicionY = std::max(posicionY - velocidad, tileSiguiente->getPosicionTileY() * Tile::altoTile);
			setPosition(getPositionX(), std::max(getPositionY() - velocidad, tileSiguiente->getPosicionTileY() * Tile::altoTile));
			//posicionY = posicionY - velocidad;
			break;
		case MOVE_DIRECTION_ABAJO:
			posicionY = std::min(posicionY + velocidad, tileSiguiente->getPosicionTileY() * Tile::altoTile);
			setPosition(getPositionX(), std::min(getPositionY() + velocidad, tileSiguiente->getPosicionTileY() * Tile::altoTile));

			//posicionY = posicionY + velocidad;
			break;
		case MOVE_DIRECTION_IZQUIERDA:
			posicionX = std::max(posicionX - velocidad, tileSiguiente->getPosicionTileX() * Tile::anchoTile);
			setPosition(std::max(getPositionX() - velocidad, tileSiguiente->getPosicionTileX() * Tile::anchoTile), getPositionY());

			//posicionX = posicionX - velocidad;
			break;
		case MOVE_DIRECTION_DERECHA:
			posicionX = std::min(posicionX + velocidad, tileSiguiente->getPosicionTileX() * Tile::anchoTile);
			setPosition(std::min(getPositionX() + velocidad, tileSiguiente->getPosicionTileX() * Tile::anchoTile), getPositionY());
			//posicionX = posicionX + velocidad;
			break;
		}

		// Asignacion de coliciones
		//
		//

		// Cambio de direccion

		if ((direccionActual == MOVE_DIRECTION_ABAJO || direccionActual == MOVE_DIRECTION_ARRIBA) && getPositionY() == tileSiguiente->getPosicionTileY() * Tile::altoTile)
			setTileActual(tileSiguiente);

		if ((direccionActual == MOVE_DIRECTION_IZQUIERDA || direccionActual == MOVE_DIRECTION_DERECHA) && getPositionX() == tileSiguiente->getPosicionTileX() * Tile::anchoTile)
			setTileActual(tileSiguiente);
	}
	
	GamePawn::update(delta);
}



void Bomberman::setTileActual(Tile* _tileNuevo)
{
	if (tileActual != nullptr){
		tileActual->setBomberman(nullptr);
	}

	tileActual = _tileNuevo;

	if (tileActual != nullptr) {
		tileActual->setBomberman(this);

		posicionX = tileActual->getPosicionTileX() * Tile::anchoTile;
		posicionY = tileActual->getPosicionTileY() * Tile::altoTile;
		setPosition(tileActual->getPosicionTileX() * Tile::anchoTile, tileActual->getPosicionTileY() * Tile::altoTile);
	}

}
