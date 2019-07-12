//
//  XDSChapterModel.h
//  XDSReader
//
//  Created by dusheng.xu on 06/07/2017.
//  Copyright © 2017 macos. All rights reserved.
//

#import <Foundation/Foundation.h>

/// MARK: 二级目录
@interface XDSCatalogueModel : NSObject

@property (nonatomic, copy) NSString *catalogueName;
@property (nonatomic, copy) NSString *link;
@property (nonatomic, copy) NSString *catalogueId;//if the id is nil, it means the catalogue is the first level catalogue 如果id为空，则为一级目录

@property (nonatomic, assign) NSInteger chapter;//章节

@end

typedef  NS_ENUM(NSInteger,LPPEBookType) {
    LPPEBookTypeTxt,
    LPPEBookTypeEpub,
    LPPEBookTypePDF,
};

/// MARK: 章节
@interface XDSChapterModel : NSObject <NSCopying,NSCoding>

/** 文章配置 */
@property (nonatomic, copy) XDSReadConfig *currentConfig;

/** epub章节路径，加载epub内容时使用该字段 */
@property (nonatomic, copy) NSString *chapterSrc;
/** txt原始内容，加载txt内容时使用该字段 */
@property (nonatomic, copy) NSString *originContent;

/** 章节名称 */
@property (nonatomic, copy) NSString *chapterName;
/** 全章的富文本 */
@property (nonatomic, readonly) NSAttributedString *chapterAttributeContent;
/** 全章的out文本 */
@property (nonatomic, readonly) NSString *chapterContent;
/** 每一页的富文本 */
@property (nonatomic, readonly) NSArray *pageAttributeStrings;
/** 每一页的普通文本 */
@property (nonatomic, readonly) NSArray *pageStrings;
/** 每一页在章节中的位置 */
@property (nonatomic, readonly) NSArray *pageLocations;
/** 章节总页数 */
@property (nonatomic, readonly) NSInteger pageCount;

/** 本章所有二级目录的Model */
@property (nonatomic, readonly) NSArray<XDSCatalogueModel *> *catalogueModelArray;
/** 存放对应id的location，用于根据链接跳转到指定页面   @{NSString:NSNumber} */
@property (nonatomic, readonly) NSDictionary *locationWithPageIdMapping;

/** 本章所有图片的链接 */
@property (nonatomic, readonly) NSArray<NSString *> *imageSrcArray;
/** 笔记 */
@property (nonatomic, readonly) NSArray<XDSNoteModel *>*notes;
/** 书签 */
@property (nonatomic, readonly) NSArray<XDSMarkModel *>*marks;

- (void)setCatalogueModelArray:(NSArray<XDSCatalogueModel *> *)catalogueModelArray;

- (void)paginateEpubWithBounds:(CGRect)bounds;
- (void)addNote:(XDSNoteModel *)noteModel;//insert a book note into chapter 向该章节中插入一条笔记
- (void)addOrDeleteABookmark:(XDSMarkModel *)markModel;//insert a bookmark into chapter 向该章节中插入一条书签

- (NSInteger)getPageWithLocationInChapter:(NSInteger)locationInChapter;
- (XDSCatalogueModel *)getCatalogueModelInChapter:(NSInteger)locationInChapter;

- (BOOL)isMarkAtPage:(NSInteger)page;
- (NSArray *)notesAtPage:(NSInteger)page;

- (BOOL)isReadConfigChanged;

@end
