//
//  CompanyAPI.h
//  yingxuntong
//
//  Created by ilikeido on 15-2-12.
//  Copyright (c) 2015年 ilikeido. All rights reserved.
//

#import "NDBaseAPI.h"
#import "Company.h"
#import "CompanyFile.h"

/**
 *  5.4.1	协议下一操作列表
 */
@interface GetNextSetpListRequest : NDBaseAPIRequest

/**
 *  1）协议当前步骤，协议新建时为空；2）协议修改时，从company.currentFlowStep获取
 */
@property(nonatomic,assign) int currentStepId;

@end

@interface GetNextSetpListResponse : NDBaseAPIResponse

@property(nonatomic,strong) NSArray * nexSteps;

@end

/**
 *  5.4.2	步骤操作人列表
 */
@interface GetStepUserListRequest : NDBaseAPIRequest

@property(nonatomic,assign) int setpId;//步骤编号

@end

@interface GetStepUserListResponse : NDBaseAPIResponse

@property(nonatomic,strong) NSArray *stepUsers;//下一操作员列表

@end


@interface CompanyPage :NDBasePage

@end

/**
 *  5.4.5	协议分页查询
 */
@interface CompanyPageRequest:NDBaseAPIRequest

@property(nonatomic,strong) NSString * orgCode;//银行机构编码(默认用户所在的银行部门)

@property(nonatomic,strong) NSString *likeDeptCode;//公司部门代码(默认用户所在的部门)

@property(nonatomic,assign) int userId;//协议申请人ID

@property(nonatomic,strong) NSString *regName;//协议商户名称

@property(nonatomic,strong) NSString *agreementCode;//协议编码

@property(nonatomic,strong) NSString *cityId;//城市编码，如：福州、厦门对应的编码

@property(nonatomic,strong) NSString *agreementYxStatus;//银讯协议状态(来自数据字典，类型：YXXYZT)


@property(nonatomic,assign) int numPerPage;//每页显示几条，默认10

@property(nonatomic,assign) int pageNum;//当前第几页

@end


/**
 *  5.4.5	协议分页查询结果
 */
@interface CompanyPageResponse : NDBaseAPIResponse

@property(nonatomic,strong) CompanyPage *page;//协议分页列表

@end

/**
 *  5.4.3	协议申请/修改
 */
@interface CompanyUpdateRequest : NDBaseAPIRequest

@property(nonatomic,strong) NSNumber *companyId;

@property(nonatomic,strong) NSNumber *userId;//申请人编号，新增时需填

@property(nonatomic,assign) int draftFlag;//草稿{1:是，0：否}

@property(nonatomic,strong) NSString *regName;//商户名称

@property(nonatomic,strong) NSString *agreementCode;//协议编号(非印刷版协议可不填)

@property(nonatomic,strong) NSString *orgCode;//所属组织机构编码(只能选择子节点)

@property(nonatomic,strong) NSString *developAvenues;//拓展渠道（来自数据字典，类型：TZQD）默认值“DSF00001 ”，该项可不显示。

@property(nonatomic,strong) NSString *originalInfoCheck;//申请资料原件检查（来自数据字典，类型：YN）默认值“1”

@property(nonatomic,strong) NSString *ifVisitInspect;//是否上门核实（来自数据字典，类型：YN）默认值“1”

@property(nonatomic,strong) NSString *provinceId;//所属省份编码（默认福建省，值35）

@property(nonatomic,strong) NSString *cityId;//所属地市（默认登录用户所在市）

@property(nonatomic,strong) NSString *countyId;//所属区县（默认登录用户所在县）

@property(nonatomic,strong) NSString *developTypeId;//申请类型,共11位；为复选复合值；按顺序{POS新装机，POS增机，POS变更名称，POS变更账号，POS缴费宝，POS开通退货，POS变更地址，POS扣率变更，POS变更绑定电话，POS撤机，POS其他信息变更} 每项中被选中的值为1，未被选中的值为0；如：10000000000，表示“POS新装机”被选中，其他的未被选中

@property(nonatomic,strong) NSString *spotCheckOpinion;//现场核查意见

@property(nonatomic,strong) NSString *otherRemark;//备注

@property(nonatomic,strong) NSNumber *deliverTypeId;//协议来源（来自数据字典，类型：DELIVER_TYPE）

@property(nonatomic,strong) NSNumber *stepId;//下一操作ID，提交审核时，需填

@property(nonatomic,strong) NSNumber *operatorId;//协议来源（来自数据字典，类型：DELIVER_TYPE）

@property(nonatomic,strong) NSNumber *currentFlowStep;//当前步骤,新建时可为空

@end

@interface CompanyUpdateResponse : NDBaseAPIResponse

@property(nonatomic,strong)Company *company;

@property(nonatomic,strong)NSString *errorCode;//失败时的错误码{001：申请人不能为空，010:协议编码已经存在，020：提交银商审核异常，009：其他异常}

@end

/**
 *  5.4.4	协议提交下一操作
 */
@interface CompanySubmitNextRequest : NDBaseAPIRequest

@property(nonatomic,assign) int companyId;//唯一编号,修改时需填
@property(nonatomic,assign) int stepId;//下一操作ID，提交审核时，需填
@property(nonatomic,strong) NSNumber *operatorId;//下一办理人ID
@property(nonatomic,strong) NSNumber *currentFlowStep;//当前步骤,新建时可为空

@end

@interface CompanySubmitNextResponse : NDBaseAPIResponse

@property(nonatomic,strong) Company *company;

@end


/**
 *  5.4.6	协议申请进度查询
 */
@interface AgreementOperHisRequest : NDBaseAPIRequest

@property(nonatomic,assign) int agreementId;//协议编号

@end

@interface AgreementOperHisResponse : NDBaseAPIResponse

@property(nonatomic,strong) NSArray *agreementOperHis;

@end

/**
 *  5.4.7	协议图片列表
 */
@interface GetCompanyfileListRequest : NDBaseAPIRequest

@property(nonatomic,assign) int companyId;//协议编号

@end

@interface GetCompanyfileListResponse : NDBaseAPIResponse

@property(nonatomic,strong) NSArray * credentialTypes;//协议编号

@end

/**
 *  5.4.8	协议删除
 */
@interface DelCompanyRequest : NDBaseAPIRequest

@property(nonatomic,strong) NSString *companyIds;//协议编号

@end

@interface DelCompanyResponse : NDBaseAPIResponse

@end

/**
 *  5.4.9	协议作废
 */
@interface CancelCompanyRequest : NDBaseAPIRequest

@property(nonatomic,assign) int companyId;//协议编号

@end

@interface CancelCompanyResponse : NDBaseAPIResponse

@end


/**
 *  5.4.10	协议资料上传
 */
@interface UpdateCompanyFileRequest : NDBaseAPIRequest

@property(nonatomic,assign) NSString * jsonCompanyFile;//将CompanyFile对象转化为Json格式字符串。

@end

@interface UpdateCompanyFileResponse : NDBaseAPIResponse

@property(nonatomic,strong) CompanyFile *companyFile;//上传后的资料信息，包括访问地址，文件名等

@end

/**
 *  5.4.11	协议资料删除
 */
@interface DelCompanyFileRequest : NDBaseAPIRequest

@property(nonatomic,strong) NSString *companyFileIds;//协议资料编号，多个用英文逗号分隔,如：1,2,3,4,5,6

@end

@interface DelCompanyFileResponse : NDBaseAPIResponse

@end


/**
 *  5.4.12	协议详情
 */
@interface ShowCompanyRequest : NDBaseAPIRequest

@property(nonatomic,assign) int companyId;

@end

@interface ShowCompanyResponse : NDBaseAPIResponse

@property(nonatomic,strong) Company *company;//协议信息，company. sourceType = 1,说明协议是银联提交的，没有下一操作;如果有下一步操作，当前操作人ID为:company.currentOperatorId当前步骤ID为:company. currentFlowSteps

@end

/**
 *  5.4.13	协议跟踪反馈新增/修改
 */
@interface FeedbackUpdateRequest : NDBaseAPIRequest

@property(nonatomic,strong) NSNumber *companyFeedbackId	;//	唯一编号,修改时需填
@property(nonatomic,assign) int 	userId	;//	反馈人编号，新增时需填
@property(nonatomic,assign) int 	companyId	;//	协议编号
@property(nonatomic,strong) NSString *realName	;//	反馈人真实姓名
@property(nonatomic,strong) NSString * 	content	;//	反馈内容
@property(nonatomic,strong) NSString * 	feedbackType	;//	反馈类型, 来自字典（字典类型typeKey= COMPANY_FEEDBACK_TYP）

@end

@interface FeedbackUpdateResponse :NDBaseAPIResponse


@end

/**
 *  5.4.14	协议跟踪反馈列表
 */
@interface FeedBackListRequest : NDBaseAPIRequest

@property(nonatomic,strong) NSNumber *companyId	;//	协议编号

@end

@interface FeedBackListResponse : NDBaseAPIResponse

@property(nonatomic,strong) NSArray *companyfeedbacks;//协议跟踪反馈列表

@end


@interface CompanyAPI : NDBaseAPI

/**
 *  获取协议下一操作列表
 *
 *  @param request 请求对象
 *  @param sucess 成功返回的Block
 *  @param fail 失败返回的Block
 *
 */
+(void)getNextSetpListByRequest:(GetNextSetpListRequest *)request completionBlockWithSuccess:(void(^)(GetNextSetpListResponse *response))sucess  Fail:(void(^)(NSString * returnCode,NSString *failDescript))fail;

/**
 *  获取步骤操作人列表
 *
 *  @param request 请求对象
 *  @param sucess 成功返回的Block
 *  @param fail 失败返回的Block
 *
 */
+(void)getStepUserListByRequest:(GetStepUserListRequest *)request completionBlockWithSuccess:(void(^)(GetStepUserListResponse *response))sucess  Fail:(void(^)(NSString * returnCode,NSString *failDescript))fail;

/**
 *  协议分页查询
 *
 *  @param request 请求对象
 *  @param sucess 成功返回的Block
 *  @param fail 失败返回的Block
 *
 */
+(void)getCompanyPageByRequest:(CompanyPageRequest *)request completionBlockWithSuccess:(void(^)(CompanyPageResponse *response))sucess  Fail:(void(^)(NSString * returnCode,NSString *failDescript))fail;

/**
 *  协议申请/修改
 *
 *  @param request 请求对象
 *  @param sucess 成功返回的Block
 *  @param fail 失败返回的Block
 *
 */
+(void)updateCompanyByRequest:(CompanyUpdateRequest *)request completionBlockWithSuccess:(void(^)(CompanyUpdateResponse *response))sucess  Fail:(void(^)(NSString * returnCode,NSString *failDescript))fail;

/**
 *  协议提交下一操作
 *
 *  @param request 请求对象
 *  @param sucess 成功返回的Block
 *  @param fail 失败返回的Block
 *
 */
+(void)submitNextByRequest:(CompanySubmitNextRequest *)request completionBlockWithSuccess:(void(^)(CompanySubmitNextResponse *response))sucess  Fail:(void(^)(NSString * returnCode,NSString *failDescript))fail;


/**
 *  协议申请进度查询
 *
 *  @param request 请求对象
 *  @param sucess 成功返回的Block
 *  @param fail 失败返回的Block
 *
 */
+(void)queryAgreementOperHisByRequest:(AgreementOperHisRequest *)request completionBlockWithSuccess:(void(^)(AgreementOperHisResponse *response))sucess  Fail:(void(^)(NSString * returnCode,NSString *failDescript))fail;


/**
 *  协议图片列表
 *
 *  @param request 请求对象
 *  @param sucess 成功返回的Block
 *  @param fail 失败返回的Block
 *
 */
+(void)getCompanyfileListByRequest:(GetCompanyfileListRequest *)request completionBlockWithSuccess:(void(^)(GetCompanyfileListResponse *response))sucess  Fail:(void(^)(NSString * returnCode,NSString *failDescript))fail;

/**
 *  协议删除
 *
 *  @param request 请求对象
 *  @param sucess 成功返回的Block
 *  @param fail 失败返回的Block
 *
 */
+(void)delCompanyByRequest:(DelCompanyRequest *)request completionBlockWithSuccess:(void(^)(DelCompanyResponse *response))sucess  Fail:(void(^)(NSString * returnCode,NSString *failDescript))fail;

/**
 *  协议作废
 *
 *  @param request 请求对象
 *  @param sucess 成功返回的Block
 *  @param fail 失败返回的Block
 *
 */
+(void)cancelCompanyByRequest:(CancelCompanyRequest *)request completionBlockWithSuccess:(void(^)(CancelCompanyResponse *response))sucess  Fail:(void(^)(NSString * returnCode,NSString *failDescript))fail;


/**
 *  协议资料上传
 *
 *  @param request 请求对象
 *  @param sucess 成功返回的Block
 *  @param fail 失败返回的Block
 *
 */
+(void)updateCompanyFileByRequest:(UpdateCompanyFileRequest *)request completionBlockWithSuccess:(void(^)(UpdateCompanyFileResponse *response))sucess  Fail:(void(^)(NSString * returnCode,NSString *failDescript))fail;

/**
 *  协议资料删除
 *
 *  @param request 请求对象
 *  @param sucess 成功返回的Block
 *  @param fail 失败返回的Block
 *
 */
+(void)delCompanyFileByRequest:(DelCompanyFileRequest *)request completionBlockWithSuccess:(void(^)(DelCompanyFileResponse *response))sucess  Fail:(void(^)(NSString * returnCode,NSString *failDescript))fail;


/**
 *  协议详情
 *
 *  @param request 请求对象
 *  @param sucess 成功返回的Block
 *  @param fail 失败返回的Block
 *
 */
+(void)showCompanyByRequest:(ShowCompanyRequest *)request completionBlockWithSuccess:(void(^)(ShowCompanyResponse *response))sucess  Fail:(void(^)(NSString * returnCode,NSString *failDescript))fail;


/**
 *  协议跟踪反馈新增/修改
 *
 *  @param request 请求对象
 *  @param sucess 成功返回的Block
 *  @param fail 失败返回的Block
 *
 */
+(void)feedbackUpdateByRequest:(FeedbackUpdateRequest *)request completionBlockWithSuccess:(void(^)(FeedbackUpdateResponse *response))sucess  Fail:(void(^)(NSString * returnCode,NSString *failDescript))fail;


/**
 *  协议跟踪反馈列表
 *
 *  @param request 请求对象
 *  @param sucess 成功返回的Block
 *  @param fail 失败返回的Block
 *
 */
+(void)getFeedBackListByRequest:(FeedBackListRequest *)request completionBlockWithSuccess:(void(^)(FeedBackListResponse *response))sucess  Fail:(void(^)(NSString * returnCode,NSString *failDescript))fail;




@end
