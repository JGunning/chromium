// Copyright (c) 2006-2008 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CHROME_BROWSER_VIEWS_FIRST_RUN_VIEW_H_
#define CHROME_BROWSER_VIEWS_FIRST_RUN_VIEW_H_

#include "chrome/browser/views/first_run_view_base.h"
#include "chrome/browser/views/first_run_customize_view.h"
#include "chrome/views/dialog_delegate.h"
#include "chrome/views/link.h"
#include "chrome/views/view.h"

namespace ChromeViews {
class Label;
class Window;
}

class Profile;
class ImporterHost;

// FirstRunView implements the dialog that welcomes to user to Chrome after
// a fresh install.
class FirstRunView : public FirstRunViewBase,
                     public ChromeViews::LinkController,
                     public FirstRunCustomizeView::CustomizeViewObserver {
 public:
  explicit FirstRunView(Profile* profile);
  virtual ~FirstRunView();

  // Overridden from ChromeViews::View:
  virtual void GetPreferredSize(CSize *out);
  virtual void Layout();

  // Overridden from ChromeViews::DialogDelegate:
  virtual bool Accept();
  virtual bool Cancel();

  // Overridden from ChromeViews::WindowDelegate:
  virtual std::wstring GetWindowTitle() const;
  virtual ChromeViews::View* GetContentsView();

  // Overridden from ChromeViews::LinkActivated:
  virtual void LinkActivated(ChromeViews::Link* source, int event_flags);

  // Overridden from FirstRunCustomizeView:
  virtual void CustomizeAccepted();
  virtual void CustomizeCanceled();

 private:
  // Initializes the controls on the dialog.
  void SetupControls();

  // Creates the dialog that allows the user to customize work items.
  void OpenCustomizeDialog();

  ChromeViews::Label* welcome_label_;
  ChromeViews::Label* actions_label_;
  ChromeViews::Label* actions_import_;
  ChromeViews::Label* actions_shorcuts_;
  ChromeViews::Link* customize_link_;
  bool customize_selected_;

  DISALLOW_COPY_AND_ASSIGN(FirstRunView);
};

#endif  // CHROME_BROWSER_VIEWS_FIRST_RUN_VIEW_H_
