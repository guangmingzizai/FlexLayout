//
//  UILabelExtension.swift
//  ActionSheetPicker-3.0
//
//  Created by wangjianfei on 2018/3/27.
//

import UIKit

public extension UILabel {
    public var flex_text: String? {
        get {
            return text
        }
        set {
            self.text = newValue
            self.flex.markDirty()
        }
    }
    
    public var flex_attributedText: NSAttributedString? {
        get {
            return attributedText
        }
        set {
            self.attributedText = newValue
            self.flex.markDirty()
        }
    }
}
