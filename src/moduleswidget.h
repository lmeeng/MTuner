//--------------------------------------------------------------------------//
/// Copyright (c) 2019 by Milos Tosic. All Rights Reserved.                ///
/// License: http://www.opensource.org/licenses/BSD-2-Clause               ///
//--------------------------------------------------------------------------//

#ifndef RTM_MTUNER_MODULESWIDGET_H
#define RTM_MTUNER_MODULESWIDGET_H

#include <MTuner/.qt/qt_ui/moduleswidget_ui.h>

struct CaptureContext;

class ModulesWidget : public QWidget
{
	Q_OBJECT

private:
	QTreeWidget*	m_treeWidget;
	CaptureContext*	m_context;

public:
	ModulesWidget(QWidget* _parent = 0, Qt::WindowFlags _flags = 0);

	void changeEvent(QEvent* _event);
	void setContext(CaptureContext* _capture);
	void setCurrentHeap(uint64_t _handle);

public Q_SLOTS:
	void ItemChanged(QTreeWidgetItem*, QTreeWidgetItem*);

Q_SIGNALS:
	void heapSelected(uint64_t);

private:
	Ui::ModulesWidget ui;
};

#endif // RTM_MTUNER_MODULESWIDGET_H