#include "resource_browser.h"
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QDebug>
#include "../util/flow_layout.h"

namespace gloom {
	resource_browser::resource_browser(resource_collection&& resources, QWidget* parent)
		: QWidget(parent) { 
		setLayout(new util::flow_layout());

		for (int i=0; i<resources.count(); ++i) {
			auto path = resources.thumbnail(i);
			auto button = new QPushButton(QPixmap(path), "");
			button->setIconSize({ 60, 60 });
			button->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
			layout()->addWidget(button);
		}
	}
}